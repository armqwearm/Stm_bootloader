# STM32F7 Bootloader Architecture

## Current scope

This document describes the initial software structure. Device-specific flash and SRAM limits, communication transport, and update protocol are intentionally placeholders until the exact target MCU and hardware interface are confirmed.

## Layers

- `Core/`: bootloader entry point and boot decision logic.
- `ApplicationInterface/`: application image metadata and validation interface.
- `Drivers/`: hardware abstraction and board-specific drivers.
- `Linker/`: memory layout and section placement.
- `Docs/`: architecture and protocol documentation.

## Application handover

The bootloader validates the application's initial MSP and reset-handler address, disables interrupts, stops SysTick, updates `SCB->VTOR`, and transfers control to the application's reset handler.

Before production use, the exact STM32F7 memory map and cache/MPU/peripheral cleanup requirements must be verified for the selected MCU and application.

## Update state machine

The planned update state machine is:

```text
RESET
  |
  v
BOOT_INIT
  |
  +--> UPDATE_REQUESTED --> RECEIVE --> VERIFY --> INSTALL --> VALIDATE
  |
  +--> APPLICATION_VALID -------------------------------> JUMP
  |
  +--> INVALID_APPLICATION --> RECOVERY / UPDATE_WAIT
```

Atomic image activation, power-loss recovery, CRC/hash verification, and version policy will be added with the final firmware-update protocol.
