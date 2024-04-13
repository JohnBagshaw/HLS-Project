// By John Bagshaw

#include "HLS_upcounter_streamingFIFO.h"

void up_counter_with_streaming (
		ap_uint<8>       *up_count,
		ap_uint<4>  modulo,
		ap_uint<8> &display_data,
		ap_uint<4> &display_enable
		) {

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE mode=ap_fifo port=up_count
#pragma HLS INTERFACE ap_none port=modulo
#pragma HLS INTERFACE ap_none port=display_data
#pragma HLS INTERFACE ap_none port=display_enable

	static unsigned int  counter = 0;

	if (*up_count == 1) {
		counter = counter + 1;
		counter = counter%modulo;
	}
	display_data = display_code[counter];
	display_enable = 0b1110;
}
