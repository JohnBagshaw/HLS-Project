// By John Bagshaw

#include "HLS_median_filter_tb.h"
#include <iostream>

int main() {
	int status = 0;

	const int n = 13;
	DATA_TYPE x[n] = {8, 6, 4, 2, 1, 2, 8, 7, 6, 5, 4, 3, 1};


	DATA_TYPE in_data;
	bool      start;
	DATA_TYPE out_data;
	bool      out_data_vld;

	for (int i = 0; i < n; i++){
		in_data = x[i];
		start = (i == 0)? 1 : 0;
		median_filter(in_data, start, out_data, out_data_vld);

		if (out_data_vld == 1) {
			std::cout << " out_data = " << out_data << std::endl;
		}
	}



	return status;
}
