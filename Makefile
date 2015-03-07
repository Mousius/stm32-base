PROJECT = miniblink
GIT_VERSION := $(shell git describe --abbrev=4 --dirty --always --tags)

.PHONY: src test

all: src firmware version

src:
	(cd src; $(MAKE) BINARY=$(PROJECT))
flash: src
	(cd src; $(MAKE) BINARY=$(PROJECT) flash)

test:
	(cd test; $(MAKE))

clean:
	(cd src; $(MAKE) clean)
	(cd test; $(MAKE) clean)

firmware:
	mkdir firmware

version:
	mv src/$(PROJECT).elf firmware/$(PROJECT)-$(GIT_VERSION).elf

include Makefile.style
