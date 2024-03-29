// By John Bagshaw

#include "HLS_median_filter.h"

DATA_TYPE med(DATA_TYPE a, DATA_TYPE b, DATA_TYPE c) {
	DATA_TYPE m;

	if (a >= b && b >=c ) {
		m = b;
	} else if (c >= b && b >=a ) {
		m = b;
	} else if (c >= a && a >=b ) {
		m = a;
	} else if (b >= a && a >=c ) {
		m = a;
	} else {
		m = c;
	}

	return m;
}

void median_filter(DATA_TYPE in_data, bool start, DATA_TYPE &out_data, bool &out_data_vld ) {
#pragma HLS PIPELINE
#pragma HLS INTERFACE ap_none port=in_data
#pragma HLS INTERFACE ap_none port=start
#pragma HLS INTERFACE ap_none port=out_data
#pragma HLS INTERFACE ap_none port=out_data_vld
#pragma HLS INTERFACE ap_ctrl_none port=return

	static int count = 0;

	static DATA_TYPE data_1 = 0;
	static DATA_TYPE data_2 = 0;
	static DATA_TYPE data_3 = 0;

	int next_count = count;
	if (start == 1) {
		count = 1;
	}

	if (count == 1) {
		data_1 = in_data;
		next_count = count+1;
		out_data_vld = 0;
	} else if (count == 2) {
		data_2 = in_data;
		next_count = count+1;
		out_data_vld = 0;
	} else if (count == 3) {
		data_3 = in_data;
		next_count = count+1;
		out_data = med(data_1, data_2, data_3);
		out_data_vld = 1;
	} else {
		out_data = med(data_2, data_3, in_data);
		data_1 = data_2;
		data_2 = data_3;
		data_3 = in_data;
		out_data_vld = 1;
		next_count = count+1;
	}

	count = next_count;

}
