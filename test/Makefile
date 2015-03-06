################################################################################
# Library configuration
OPENCM3_DIR = ../libopencm3

################################################################################
# Compiler arguments
DEFS = -DSTM32F4

################################################################################
# Coverage
CFLAGS += -O0 --coverage
LDFLAGS += -lgcov -lcmocka

################################################################################
# Grab all _test.c files and translate to runners
CFILES=$(shell find . -name \*_test.c)
RUNNERS=$(patsubst %_test.c, %.bin, $(CFILES))

all: $(RUNNERS)
	../scripts/gcovr --object-directory=. -r ../src

clean:
	$(RM) *.bin *.gcov *.gcda *.gcno *.o

%.bin: %.o %_test.o
	gcc -o $(*).bin $(*).o $(*)_test.o $(LDFLAGS)
	./$(*).bin

%_test.o:
	gcc -c -o $(*)_test.o $(*)_test.c $(CFLAGS)

%.o:
	gcc -c -o $(*).o ../src/$(*).c  -I$(OPENCM3_DIR)/include $(DEFS) ${CFLAGS}

