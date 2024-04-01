// By John bagshaw

#include "HLS_timer_signal_tb.h"
#include <iostream>
using namespace std;

int main() {
	int status = 0;

	bool output_signal;

	cout << endl;
	for (int i = 0; i <5 * SIGNAL_PERIOD; i++) {
		timer_signal(output_signal);
		cout << output_signal ;
	}
	cout << endl;


	return status;
}
