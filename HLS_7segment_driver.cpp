// By John Bagshaw

#include "HLS_7segment_driver.h"

typedef enum {dis1, dis2, dis3, dis4} display_state_type;


void seven_segment_driver(
		bool       refresh_signal,

		ap_uint<4> first_digit,
		ap_uint<4> second_digit,
		ap_uint<4> third_digit,
		ap_uint<4> forth_digit,

		ap_uint<8> &seven_segment_data,
		ap_uint<4> &seven_segment_enable) {
#pragma HLS PIPELINE


#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=first_digit
#pragma HLS INTERFACE ap_none port=second_digit
#pragma HLS INTERFACE ap_none port=third_digit
#pragma HLS INTERFACE ap_none port=forth_digit
#pragma HLS INTERFACE ap_none port=refresh_signal
#pragma HLS INTERFACE ap_none port=seven_segment_data
#pragma HLS INTERFACE ap_none port=seven_segment_enable

	static display_state_type state = dis1;

	ap_uint<8> seven_segment_data_local;
	ap_uint<4> seven_segment_enable_local;

	display_state_type next_state;

	switch(state) {
	case dis1:

		if (refresh_signal) {
			next_state = dis2;
			seven_segment_data_local   = seven_segment_code[second_digit];
			seven_segment_enable_local = 0b1110;
		} else {
			next_state = dis1;
			seven_segment_data_local   = seven_segment_code[first_digit];
			seven_segment_enable_local = 0b1110;
		}
		break;
	case dis2:
		if (refresh_signal) {
			next_state = dis3;
			seven_segment_data_local = seven_segment_code[third_digit];
			seven_segment_enable_local = 0b1101;

		} else {
			next_state = dis2;
			seven_segment_data_local = seven_segment_code[second_digit];
			seven_segment_enable_local = 0b1101;

		}
		break;
	case dis3:

		if (refresh_signal) {
			next_state = dis4;
			seven_segment_data_local   = seven_segment_code[forth_digit];
			seven_segment_enable_local = 0b1011;

		} else {
			next_state = dis3;
			seven_segment_data_local   = seven_segment_code[third_digit];
			seven_segment_enable_local = 0b1011;

		}

		break;
	case dis4:
		if (refresh_signal) {
			next_state = dis1;
			seven_segment_data_local   = seven_segment_code[first_digit];
			seven_segment_enable_local = 0b0111;

		} else {
			next_state = dis4;
			seven_segment_data_local   = seven_segment_code[forth_digit];
			seven_segment_enable_local = 0b0111;

		}
		break;
	default:
		break;
	}

	state = next_state;
	seven_segment_data   = seven_segment_data_local;
	seven_segment_enable = seven_segment_enable_local;

}
