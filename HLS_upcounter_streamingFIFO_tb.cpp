// By John Bagshaw

#include "HLS_upcounter_streamingFIFO_tb.h"
#include <iostream>

int main() {
	int status = 0;

	ap_uint<8> up_count;
	ap_uint<8> display_data;
	ap_uint<4> display_enable;
	ap_uint<4> modulo = 10;;

	for (int i = 0; i < 20; i++) {
		up_count = 1;
		up_counter_with_streaming(&up_count, modulo, display_data, display_enable);

		up_count = 0;
		up_counter_with_streaming(&up_count, modulo, display_data, display_enable);
	}
	return status;
}

