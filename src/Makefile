################################################################################
# Library configuration
OPENCM3_DIR = ../libopencm3
LDSCRIPT = stm32f4-discovery.ld

################################################################################
# Compiler arguments

LIBNAME		= opencm3_stm32f4
DEFS		= -DSTM32F4

FP_FLAGS	?= -mfloat-abi=hard -mfpu=fpv4-sp-d16
ARCH_FLAGS	= -mthumb -mcpu=cortex-m4 $(FP_FLAGS)

################################################################################
# OpenOCD specific variables

OOCD		?= openocd
OOCD_INTERFACE	?= stlink-v2
OOCD_BOARD	?= stm32f4discovery

################################################################################
# Black Magic Probe specific variables
# Set the BMP_PORT to a serial port and then BMP is used for flashing
BMP_PORT	?=

################################################################################
# texane/stlink specific variables
#STLINK_PORT	?= :4242

################################################################################
# Compile all the .c files to link into the binary
CFILES=$(shell find . -name \*.c)
OBJS=$(CFILES:.c=.o)

include ../Makefile.rules
