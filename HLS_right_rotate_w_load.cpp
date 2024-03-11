// By John Bagshaw

#include "HLS_right_rotate_w_load.h"

void HLS_right_rotate_w_load(ap_uint<W> data_in, bool load, bool rotate, ap_uint<W> &data_out){
#pragma HLS INTERFACE ap_ctrl_none port = return
#pragma HLS INTERFACE ap_none port = data_in
#pragma HLS INTERFACE ap_none port = load
#pragma HLS INTERFACE ap_none port = rotate
#pragma HLS INTERFACE ap_none port = data_out
#pragma HLS PIPELINE II=1

	static ap_uint<W> rotate_reg = 0;

	if(load == 1){
		rotate_reg = data_in;
	}
	if(rotate == 1){
		rotate_reg.rrotate(1);
	}

	data_out = rotate_reg;
}
