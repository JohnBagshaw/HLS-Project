// By John Bagshaw

#include "HLS_pulse_gen_streamingFIFO_tb.h"
#include <iostream>
#include "ap_int.h"

int main() {

	int status = 0;
	ap_uint<8> pulse;

	std::cout << " pulse = " ;
	for (int i = 0; i < 5; i++) {
		 pulse_generator_streaming(0, &pulse);
		std::cout << " " << pulse ;
	}

	for (int i = 0; i < 5; i++) {
		pulse_generator_streaming(1, &pulse);
		std::cout << " " << pulse ;
	}

	for (int i = 0; i < 5; i++) {
		pulse_generator_streaming(0, &pulse);
		std::cout << " " << pulse ;
	}

	std::cout << std::endl ;
	return status;
}
