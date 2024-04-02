// By John Bagshaw

#pragma once
#include "HLS_pmod_keyboard.h"

void pmod_keyboard(
		ap_uint<4>  rows,
		ap_uint<4> &cols,
		bool        input_refresh_signal,
		ap_uint<8> &display_data,
		ap_uint<4> &display_enable );
