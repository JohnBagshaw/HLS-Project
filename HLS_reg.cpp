// By John Bagshaw

#include "HLS_reg.h"

void HLS_reg(bool data, ap_uint<5> &n){
#pragma HLS INTERFACE ap_ctrl_none port = return
#pragma HLS INTERFACE ap_none port = data
#pragma HLS INTERFACE ap_none port = n
#pragma HLS PIPELINE II=1

	static ap_uint<5> reg = 0b00000;

	reg = reg >> 1;
	reg[4] = data;

	n = reg;
}
