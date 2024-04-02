
// By John Bagshaw

#include "HLS_pmod_keyboard_tb.h"
int main() {
	int status = 0;
	ap_uint<4> rows;
	ap_uint<4> cols;
	bool       input_refresh_signal;
	ap_uint<8> display_data;
	ap_uint<4> display_enable;



	rows = 0b1111;
	input_refresh_signal = 0;
	pmod_keyboard( rows, cols, input_refresh_signal, display_data, display_enable);
	pmod_keyboard( rows, cols, input_refresh_signal, display_data, display_enable);

	rows = 0b1110;
	input_refresh_signal = 0;
	pmod_keyboard( rows, cols, input_refresh_signal, display_data, display_enable);

	input_refresh_signal = 1;
	pmod_keyboard( rows, cols, input_refresh_signal, display_data, display_enable);

	input_refresh_signal = 0;
	pmod_keyboard( rows, cols, input_refresh_signal, display_data, display_enable);
	pmod_keyboard( rows, cols, input_refresh_signal, display_data, display_enable);

	return status;
}
