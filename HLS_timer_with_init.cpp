// By John Bagshaw

#include "HLS_timer_with_init.h"


void timer_with_init(
		ap_uint<6> minutes,
		bool       begin,
		bool       pulse,
		ap_uint<4> &first_digit,
		ap_uint<4> &second_digit,
		ap_uint<4> &third_digit,
		ap_uint<4> &forth_digit )
{

#pragma HLS INTERFACE ap_none port=first_digit
#pragma HLS INTERFACE ap_none port=second_digit
#pragma HLS INTERFACE ap_none port=third_digit
#pragma HLS INTERFACE ap_none port=forth_digit
#pragma HLS INTERFACE ap_none port=pulse
#pragma HLS INTERFACE ap_none port=begin
#pragma HLS INTERFACE ap_none port=minutes
#pragma HLS INTERFACE ap_ctrl_none port=return

#pragma HLS PIPELINE



	static ap_uint<6> timer_minutes_state = 0;
	static ap_uint<6> timer_seconds_state = 0;

	if (begin == 1) {
		timer_minutes_state = minutes;
		timer_seconds_state = 0;
	}

	if (pulse == 1) {
		if (timer_minutes_state == 0) {
			if (timer_seconds_state == 0) {
				timer_seconds_state = 0;
				timer_minutes_state = 0;
			} else {
				timer_seconds_state--;
			}
		} else {
			if (timer_seconds_state == 0) {
				timer_seconds_state = 59;
				timer_minutes_state--;
			} else {
				timer_seconds_state--;
			}
		}
	}

	first_digit  = timer_seconds_state%10;
	second_digit = timer_seconds_state/10;

	third_digit = timer_minutes_state%10;
	forth_digit = timer_minutes_state/10;
}
