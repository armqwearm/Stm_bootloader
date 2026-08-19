#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#include <stdbool.h>
#include <stdint.h>

bool Bootloader_IsApplicationValid(void);
void Bootloader_JumpToApplication(void);
void Bootloader_Run(void);

#endif
