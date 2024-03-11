// By John Bagshaw

#include "HLS_right_rotate_w_load_tb.h"
#include <iostream>
#include <bitset>
using namespace std;

int main(){
	int status = 0;

	ap_uint<W> data_in;
	bool load;
	bool rotate;
	ap_uint<W> data_out;

	data_in = 0x24;
	load = 1;
	rotate = 0;
	HLS_right_rotate_w_load(data_in, load, rotate, data_out);

	cout << " data_in = " << setfill('0') << setw(W) << (bitset<W>)data_in
			<< " load = " << load << " rotate = " << rotate << " data_out = "
			<< setfill('0') << setw(W) << (bitset<W>)data_out << endl;

	load = 0;
	rotate = 1;
	for(int i = 0; i < 8; i++){
		HLS_right_rotate_w_load(data_in, load, rotate, data_out);

		cout << " data_in = " << setfill('0') << setw(W) << (bitset<W>)data_in
				<< " load = " << load << " rotate = " << rotate << " data_out = "
				<< setfill('0') << setw(W) << (bitset<W>)data_out << endl;
	}
	return status;
}
