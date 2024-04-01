// By John Bagshaw

#pragma once
#include "HLS_timer_with_init.h"


void timer_with_init(
		ap_uint<6> minutes,
		bool       begin,
		bool       pulse,
		ap_uint<4> &first_digit,
		ap_uint<4> &second_digit,
		ap_uint<4> &third_digit,
		ap_uint<4> &forth_digit );
