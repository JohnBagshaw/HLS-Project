// By John Bagshaw

#pragma once

#include "HLS_7segment_driver.h"


void seven_segment_driver(
		bool       refresh_signal,

		ap_uint<4> first_digit,
		ap_uint<4> second_digit,
		ap_uint<4> third_digit,
		ap_uint<4> forth_digit,

		ap_uint<8> &seven_segment_data,
		ap_uint<4> &seven_segment_enable);
