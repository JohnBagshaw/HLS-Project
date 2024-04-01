// By John Bagshaw

#include "HLS_timer_with_init_tb.h"

int main() {
	int status = 0;
	ap_uint<6> minutes = 9;

	bool       begin;
	bool       pulse;
	ap_uint<4> first_digit;
	ap_uint<4> second_digit;
	ap_uint<4> third_digit;
	ap_uint<4> forth_digit;


	timer_with_init( minutes, begin, pulse, first_digit, second_digit, third_digit, forth_digit );
}
