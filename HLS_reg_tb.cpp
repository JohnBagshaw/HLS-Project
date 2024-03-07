// By John Bagshaw

#include "HLS_reg_tb.h"
#include <iostream>
using namespace std;

int main(){
	int status = 0;

	bool data;
	ap_uint<5> n;

	cout << "data, n" << endl;

	data = 1;
	HLS_reg(data, n);
	cout << data << ", " << n.to_string() << endl;

	data = 1;
	HLS_reg(data, n);
	cout << data << ", " << n.to_string() << endl;

	data = 0;
	HLS_reg(data, n);
	cout << data << ", " << n.to_string() << endl;

	data = 1;
	HLS_reg(data, n);
	cout << data << ", " << n.to_string() << endl;

	data = 0;
	HLS_reg(data, n);
	cout << data << ", " << n.to_string() << endl;

	return status;
}
