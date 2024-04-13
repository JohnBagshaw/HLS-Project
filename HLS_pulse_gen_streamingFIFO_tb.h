// By John Bagshaw

#pragma once

#include "HLS_pulse_gen_streamingFIFO.h"
#include "ap_int.h"

void pulse_generator_streaming(bool input, ap_uint<8> *pulse);
