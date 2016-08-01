#include "WProgram.h"

#include <vector>

using namespace std;

vector<int> pins = {13, 14, 15, 16};

void setup ()
{
	for (int p : pins) {
		pinMode(p, OUTPUT);
	}
}

void loop ()
{
	for (int p : pins) {
		digitalWriteFast(p, HIGH);
	}

	delay(500);

	for (int p : pins) {
		digitalWriteFast(p, LOW);
	}

	delay(500);
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
