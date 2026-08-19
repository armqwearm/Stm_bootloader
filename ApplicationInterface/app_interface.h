#ifndef APP_INTERFACE_H
#define APP_INTERFACE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    uint32_t magic;
    uint32_t image_size;
    uint32_t image_crc;
    uint32_t version;
} FirmwareHeader_t;

bool AppInterface_IsImageValid(const FirmwareHeader_t *header);

#endif
