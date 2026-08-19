# Bootloader Project Notes

This directory contains design notes and implementation decisions for the STM32F7 bootloader.

## Decisions pending

1. Exact STM32F7 part number and flash size.
2. Exact application start address.
3. Firmware update transport (UART, CAN/CAN-FD, USB, Ethernet, etc.).
4. Update frame format and timeout rules.
5. CRC/hash algorithm.
6. Firmware version and rollback policy.
7. Power-loss recovery strategy.
8. Watchdog strategy.

No device-specific value should be treated as final until the target hardware is confirmed.
