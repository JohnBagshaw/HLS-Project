// By John Bagshaw

#include "HLS_7segment_driver_tb.h"
#include <iostream>
#include <map>

std::map<ap_uint<8>,int> digit = {
		{0b11000000, 0},
		{0b11111001, 1},
		{0b10100100, 2},
		{0b10110000, 3},
		{0b10011001, 4},
		{0b10010010, 5},
		{0b10000010, 6},
		{0b11111000, 7},
		{0b10000000, 8},
		{0b10010000, 9}
};
int main() {

	int status = 0;

	bool refresh_signal = 0;

	ap_uint<4> first_digit  = 7;
	ap_uint<4> second_digit = 5;
	ap_uint<4> third_digit  = 3;
	ap_uint<4> forth_digit  = 1;

	ap_uint<8> seven_segment_data;
	ap_uint<4> seven_segment_enable;


	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {

			seven_segment_driver(
				refresh_signal,

				first_digit,
				second_digit,
				third_digit,
				forth_digit,

				seven_segment_data,
				seven_segment_enable);
			std::cout << digit[seven_segment_data] << "(" << seven_segment_enable.to_string() << ")  " ;
			refresh_signal = 0;

		}
		refresh_signal = 1;

	}


	if (status == 0) {
		std::cout << "Test Passed!" << std::endl;
	} else {
		std::cout << "Test Failed!" << std::endl;
	}


	return status;
}
