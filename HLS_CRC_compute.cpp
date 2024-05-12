#include "HLS_CRC_compute.h"

void crc_compute(hls::stream<axi_interface>& input_stream, hls::stream<axi_interface>& output_stream, crc_t crc_poly) {
    #pragma HLS INTERFACE axis port=input_stream
    #pragma HLS INTERFACE axis port=output_stream
    #pragma HLS INTERFACE s_axilite port=crc_poly
    #pragma HLS INTERFACE s_axilite port=return

    axi_interface input, output;
    crc_t crc = 0x3F;  // Set initial CRC mask to all 1's in the 6-bit CRC field

    while (!input_stream.empty()) {
        input = input_stream.read();
        if (input.tvalid && input.tready) {
            data_t data = input.tdata;
            crc = 0x3F;  // Reset CRC to all 1's for each new input
            for (int i = 0; i < 32; ++i) {
                bool bit = (crc >> 5) ^ ((data >> (31 - i)) & 1);  // Process bit-by-bit
                crc <<= 1;
                if (bit) {
                    crc ^= crc_poly;  // Apply polynomial
                }
                crc &= 0x3F;  // Ensure CRC remains within 6 bits
            }
            output.tdata = crc;
            output.tvalid = true;
            output.tready = input.tready;
            output_stream.write(output);
        }
    }
}
