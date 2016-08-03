SHELL := /bin/bash

all: main.hex main.elf

main.hex: main.cc
	cp main.cc lib/main.cpp
	cd lib ; make
	cp lib/main.hex main.hex

main.elf:
	g++ -std=c++11 -O0 -Wall main.cc -o main.elf -DTESTING_MODE

test: all
	timeout --preserve-status -k 2 1 ./main.elf

load: main.hex
	sudo $$(which teensy_loader_cli) -v -mmcu=mk20dx256 -w main.hex

clean:
	rm -f main.hex
	rm -f main.elf

purge: clean
	cd lib ; make clean
