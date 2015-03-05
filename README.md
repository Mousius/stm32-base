# STM32F4 Base

**WORK IN PROGRESS**

Base repository for building firmware to upload to the STM32F4 Discovery board.

## Directories

### firmware
Output directory for single firmware generated from src into elf format for flashing.

### src
Source files.

### test
Directory for containing tests which are ran using the system compiler to run coverage.

### libopencm3
Abstraction library for Cortex M3 microcontrollers.

## Commands

### make
Builds the files in `src` into `firmware`

### make test
Builds and runs `test/coverage`

### make clean
Remove build files from `test` and `src`.

### make flash
Builds `firmware` and then runs openocd to flash the firmware onto the board.
