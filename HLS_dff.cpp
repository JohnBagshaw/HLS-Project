// By John Bagshaw

#include "HLS_dff.h"

void HLS_dff(bool data, bool &n1, bool &n2, bool &n3){
#pragma HLS INTERFACE ap_none port = data
#pragma HLS INTERFACE ap_none port = n1
#pragma HLS INTERFACE ap_none port = n2
#pragma HLS INTERFACE ap_none port = n3
#pragma HLS INTERFACE ap_ctrl_none port = return
#pragma HLS PIPELINE II=1

	volatile static bool dff_0 = 0;
	static bool dff_1 = 0;
	static bool dff_2 = 0;
	static bool dff_3 = 0;

	dff_3 = dff_2;
	dff_2 = dff_1;
	dff_1 = dff_0;
	dff_0 = data;

	n1 = dff_1;
	n2 = dff_2;
	n3 = dff_3;
}
