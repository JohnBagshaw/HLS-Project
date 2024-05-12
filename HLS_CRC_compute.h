#ifndef CRC_COMPUTE_H_
#define CRC_COMPUTE_H_

#include "hls_stream.h"
#include "ap_int.h"

typedef ap_uint<32> data_t;
typedef ap_uint<6> crc_t;

typedef struct {
    data_t tdata;
    bool tvalid;
    bool tready;
} axi_interface;

void crc_compute(hls::stream<axi_interface> &input_stream, hls::stream<axi_interface> &output_stream, crc_t crc_poly);

#endif // CRC_COMPUTE_H_
