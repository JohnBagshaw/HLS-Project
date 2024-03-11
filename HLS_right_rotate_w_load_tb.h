// By John Bagshaw

#pragma once
#include "HLS_right_rotate_w_load.h"

void HLS_right_rotate_w_load(ap_uint<W> data_in, bool load, bool rotate, ap_uint<W> &data_out);
