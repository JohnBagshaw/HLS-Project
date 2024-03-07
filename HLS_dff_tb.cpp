// By John Bagshaw

#include "HLS_dff_tb.h"
#include <iostream>
using namespace std;

int main(){

	int status = 0;

	bool data;
	bool n1;
	bool n2;
	bool n3;

	cout << "data| n1, n2, n3 " << endl;
	cout << "-----------------" << endl;

	data = 1;
	HLS_dff(data, n1, n2, n3);
	cout << data << "   | " << n1 << ", " << n2 << ", " << n3 << endl;

	data = 1;
	HLS_dff(data, n1, n2, n3);
	cout << data << "   | " << n1 << ", " << n2 << ", " << n3 << endl;

	data = 0;
	HLS_dff(data, n1, n2, n3);
	cout << data << "   | " << n1 << ", " << n2 << ", " << n3 << endl;

	data = 1;
	HLS_dff(data, n1, n2, n3);
	cout << data << "   | " << n1 << ", " << n2 << ", " << n3 << endl;

	data = 0;
	HLS_dff(data, n1, n2, n3);
	cout << data << "   | " << n1 << ", " << n2 << ", " << n3 << endl;

	cout << "-------------------" << endl;

	return status;

}
