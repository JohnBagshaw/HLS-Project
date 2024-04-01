// By John Bagshaw

#include "HLS_7segment_signal_tb.h"
#include <iostream>
using namespace std;

int main() {

	int status = 0;

	bool output_signal;

	cout << endl;
	for (int i = 0; i <2 * SIGNAL_PERIOD; i++) {
		seven_segment_signal(output_signal);
		cout << output_signal ;
	}
	cout << endl;

	return status;
}
