#ifndef BOOTLOADER_CONFIG_H
#define BOOTLOADER_CONFIG_H

#include <stdint.h>

/* Initial layout. Update these values for the exact STM32F7 device. */
#define BOOTLOADER_FLASH_START   (0x08000000UL)
#define BOOTLOADER_FLASH_SIZE    (0x00020000UL) /* 128 KiB placeholder */
#define APPLICATION_FLASH_START  (BOOTLOADER_FLASH_START + BOOTLOADER_FLASH_SIZE)

#define FLASH_END_ADDRESS        (0x08200000UL) /* placeholder */

#define APPLICATION_VECTOR_SIZE  (8UL)
#define BOOTLOADER_MAGIC         (0x424F4F54UL) /* 'BOOT' */

#endif
