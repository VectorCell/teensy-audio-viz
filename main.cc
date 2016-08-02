#include "WProgram.h"

#include <vector>

using namespace std;

const int P_LED = 13;

vector<int> pins = {21, 22, 23};

void setup ()
{
	pinMode(P_LED, OUTPUT);
	for (int p : pins) {
		pinMode(p, OUTPUT);
	}
}

int main (void)
{
	setup();

	unsigned int pass = 0;
	int level = LOW;
	while (true) {
		if ((pass & 0xfffff) == 0) {
			level = (level == LOW) ? HIGH : LOW;
			digitalWriteFast(P_LED, level);
		}
		++pass;
	}
}
