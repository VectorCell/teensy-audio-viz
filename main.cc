#include "WProgram.h"

extern "C" int main(void)
{
#ifdef USING_MAKEFILE

	// To use Teensy 3.0 without Arduino, simply put your code here.
	// For example:

	pinMode(16, OUTPUT);
	pinMode(15, OUTPUT);
	pinMode(14, OUTPUT);
	pinMode(13, OUTPUT);
	while (1) {
		for (int pin = 14; pin <= 16; ++pin)
			digitalWriteFast(pin, HIGH);
		digitalWriteFast(13, HIGH);
		delay(500);
		for (int pin = 14; pin <= 16; ++pin)
			digitalWriteFast(pin, LOW);
		digitalWriteFast(13, LOW);
		delay(500);
	}


#else
	// Arduino's main() function just calls setup() and loop()....
	setup();
	while (1) {
		loop();
		yield();
	}
#endif
}

