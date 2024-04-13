#pragma once
#include "HLS_upcounter_streamingFIFO.h"

void up_counter_with_streaming(
		ap_uint<8>      *up_count,
		ap_uint<4> modulo,
		ap_uint<8> &seven_segment_data,
		ap_uint<4> &seven_segment_enable
		);
