#include "WProgram.h"

#include <vector>

using namespace std;

const int P_LED = 13;

vector<int> pins = {21, 22, 23};

int level = 0;
bool inc = true;
int iter = 0;

void setup ()
{
	pinMode(P_LED, OUTPUT);
	for (int p : pins) {
		pinMode(p, OUTPUT);
	}
}

void loop ()
{
	for (int p : pins) {
		if (inc) {
			++level;
			if (level > 255) {
				inc = false;
				--level;
			}
		} else {
			--level;
			if (level < 0) {
				inc = true;
				++level;
			}
		}
		analogWrite(p, level);
	}
	delay(5);

}

int main (void)
{
	setup();
	while (1) {
		loop();
	}

	//pinMode(13, OUTPUT);
	//while (1) {
	//	digitalWriteFast(13, HIGH);
	//	delay(500);
	//	digitalWriteFast(13, LOW);
	//	delay(500);
	//}
}
