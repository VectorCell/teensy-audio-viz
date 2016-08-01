SHELL := /bin/bash

all: main.hex

main.hex:
	cp main.cc lib/main.cpp
	cd lib ; make
	cp lib/main.hex main.hex

load: main.hex
	if [ ! -e /etc/udev/rules.d/49-teensy.rules ]; then                 \
		sudo cp 49-teensy.rules /etc/udev/rules.d/49-teensy.rules       \
		echo "ERROR: Unplug and replug Teensy, and try again"           \
	else                                                                \
		teensy_loader_cli -v -mmcu=mk20dx256 -w main.hex && rm main.hex \
	fi

clean:
	cd lib ; make clean
