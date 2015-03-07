# STM32 Base

**WORK IN PROGRESS**

[![Build Status](https://travis-ci.org/DaMouse404/stm32-base.svg?branch=master)](https://travis-ci.org/DaMouse404/stm32-base)
[![Coverage Status](https://coveralls.io/repos/DaMouse404/stm32-base/badge.svg?branch=master)](https://coveralls.io/r/DaMouse404/stm32-base?branch=master)

Base repository for building firmware to upload to a STM32 Discovery board.

## Dependencies
This base image was created with Debian Testing and has the following dependencies:

### Build

* `apt-get install gcc-arm-none-eabi`

### Testing

* `apt-get install gcc libcmocka0 libcmocka-dev`

### Coveralls

* `apt-get install python-pip`
* `pip install cpp-coveralls`

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
