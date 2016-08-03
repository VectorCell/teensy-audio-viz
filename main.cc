#ifdef TESTING_MODE
	#include "test_harness.h"
#else
	#include "WProgram.h"
#endif

#include <vector>
#include <cmath>

using namespace std;


#define TWOPI (2 * PI)

#define P_LED  13
#define P_READ 21
vector<int> pwm_pins = {20, 22, 23};

#define N_SAMPLES 2048
double sample[N_SAMPLES];


void setup ()
{
	#ifdef TESTING_MODE
		set_signal_handlers();
	#else
		// set clock speed here
		Serial.begin(9600);
	#endif

	pinMode(P_READ,  INPUT);

	pinMode(P_LED, OUTPUT);
	for (int p : pwm_pins) {
		pinMode(p, OUTPUT);
	}
}


void gather_data (double *data, int n)
{
	while (--n >= 0) {
		data[n] = analogRead(P_READ) / 1024.0;
	}
}


void fft (double *data, int nn, int isign)
{
	int n, mmax, m, j, istep, i;
	double wtemp, wr, wpr, wpi, wi, theta;
	double tempr, tempi;
	
	n = nn << 1;
	j = 1;
	for (i = 1; i < n; i += 2) {
		if (j > i) {
			tempr = data[j];     data[j] = data[i];     data[i] = tempr;
			tempr = data[j+1]; data[j+1] = data[i+1]; data[i+1] = tempr;
		}
		m = n >> 1;
		while (m >= 2 && j > m) {
			j -= m;
			m >>= 1;
		}
		j += m;
	}
	mmax = 2;
	while (n > mmax) {
		istep = 2*mmax;
		theta = TWOPI/(isign*mmax);
		wtemp = sin(0.5*theta);
		wpr = -2.0*wtemp*wtemp;
		wpi = sin(theta);
		wr = 1.0;
		wi = 0.0;
		for (m = 1; m < mmax; m += 2) {
			for (i = m; i <= n; i += istep) {
			j =i + mmax;
			tempr = wr*data[j]   - wi*data[j+1];
			tempi = wr*data[j+1] + wi*data[j];
			data[j]   = data[i]   - tempr;
			data[j+1] = data[i+1] - tempi;
			data[i] += tempr;
			data[i+1] += tempi;
			}
			wr = (wtemp = wr)*wpr - wi*wpi + wr;
			wi = wi*wpr + wtemp*wpi + wi;
		}
		mmax = istep;
	}
}


int main (void)
{
	setup();

	while (true) {
		
		//digitalWriteFast(P_LED, HIGH);
		//gather_data(sample, N_SAMPLES);
		//digitalWriteFast(P_LED, LOW);
		//fft(sample, N_SAMPLES, 1);

		#ifndef TESTING_MODE
			digitalWriteFast(P_LED, HIGH);
			//usb_serial_write("JELLO, WORLD!\n", strlen("JELLO, WORLD!\n"));
			Serial.println("JELLO, WORLD!");
			delay(500);
			digitalWriteFast(P_LED, LOW);
			//usb_serial_write("JELLO, WORLD!\n", strlen("JELLO, WORLD!\n"));
			Serial.println("JELLO, WORLD!");
			delay(500);
		#endif
	}
}
