#include "bootloader.h"
#include "bootloader_config.h"

#include <stdint.h>

#define SRAM_START  (0x20000000UL)
#define SRAM_END    (0x20080000UL) /* Placeholder; device-specific value required. */
#define THUMB_MASK  (0x1UL)

typedef void (*ApplicationEntry_t)(void);

static bool is_valid_stack_pointer(uint32_t sp)
{
    return (sp >= SRAM_START) && (sp < SRAM_END);
}

static bool is_valid_reset_handler(uint32_t reset_handler)
{
    return ((reset_handler >= APPLICATION_FLASH_START) &&
            (reset_handler < FLASH_END_ADDRESS) &&
            ((reset_handler & THUMB_MASK) != 0U));
}

bool Bootloader_IsApplicationValid(void)
{
    const uint32_t *vector_table = (const uint32_t *)APPLICATION_FLASH_START;
    return is_valid_stack_pointer(vector_table[0]) &&
           is_valid_reset_handler(vector_table[1]);
}

void Bootloader_JumpToApplication(void)
{
    const uint32_t *vector_table = (const uint32_t *)APPLICATION_FLASH_START;
    const uint32_t application_msp = vector_table[0];
    const uint32_t reset_handler = vector_table[1];

    if (!is_valid_stack_pointer(application_msp) ||
        !is_valid_reset_handler(reset_handler))
    {
        return;
    }

    __disable_irq();
    SysTick->CTRL = 0U;
    SysTick->LOAD = 0U;
    SysTick->VAL = 0U;

    SCB->VTOR = APPLICATION_FLASH_START;
    __DSB();
    __ISB();

    __set_MSP(application_msp);
    ((ApplicationEntry_t)reset_handler)();
}

void Bootloader_Run(void)
{
    if (Bootloader_IsApplicationValid())
    {
        Bootloader_JumpToApplication();
    }

    /* Firmware update state machine will be implemented here. */
    while (1)
    {
    }
}
