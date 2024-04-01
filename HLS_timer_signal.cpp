// By John Bagshaw

#include "HLS_timer_signal.h"

void timer_signal(bool &output_signal) {
#pragma HLS INTERFACE ap_none port=output_signal
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS PIPELINE II=1

	static int count = SIGNAL_PERIOD-1;

	int next_count = count;

	bool next_output_signal;

	if (count == 0) {
		next_output_signal = 1;
		next_count = SIGNAL_PERIOD-1;
	} else {
		next_output_signal = 0;
		next_count = count-1;
	}

	count = next_count;
	output_signal= next_output_signal;
}
