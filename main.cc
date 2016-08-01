#include "WProgram.h"

int main (void)
{
	pinMode(14, OUTPUT);
	while (1) {
		digitalWriteFast(14, HIGH);
		delay(500);
		digitalWriteFast(14, LOW);
		delay(500);
	}
}
