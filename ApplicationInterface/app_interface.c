#include "app_interface.h"
#include "bootloader_config.h"

bool AppInterface_IsImageValid(const FirmwareHeader_t *header)
{
    if (header == 0)
    {
        return false;
    }

    if (header->magic != BOOTLOADER_MAGIC)
    {
        return false;
    }

    if (header->image_size == 0U)
    {
        return false;
    }

    /* CRC verification will be added when the update protocol is defined. */
    return true;
}
