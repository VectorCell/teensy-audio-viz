SHELL := /bin/bash

all: main.hex

main.hex: main.cc
	cp main.cc lib/main.cpp
	cd lib ; make
	cp lib/main.hex main.hex

load: main.hex
	sudo $$(which teensy_loader_cli) -v -mmcu=mk20dx256 -w main.hex
	rm main.hex

clean:
	cd lib ; make clean
