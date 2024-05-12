#include <iostream>
#include "HLS_CRC_compute.h"
#include "hls_stream.h"

int main() {
    hls::stream<axi_interface> input_stream, output_stream;
    axi_interface input, output;

    crc_t crc_poly = 0x21;  // Correct polynomial for my use case

    // Load test data into the stream
    input.tdata = 0xBBBBDDDD;  // Example data
    input.tvalid = true;
    input.tready = true;
    input_stream.write(input);

    crc_compute(input_stream, output_stream, crc_poly);

    int error_count = 0;

    // Only read if output stream is not empty
    if (!output_stream.empty()) {
        output = output_stream.read();
        if (output.tvalid && output.tready) {
            crc_t expected_crc = 0x27;  // Expected CRC for the test case
            if (output.tdata != expected_crc) {
                std::cerr << "Test failed: Expected CRC: " << expected_crc << ", got: " << output.tdata << std::endl;
                error_count++;
            } else {
                std::cout << "Test passed: CRC matches expected " << output.tdata << std::endl;
            }
        }
    } else {
        std::cerr << "No output available." << std::endl;
        error_count++;
    }

    return error_count;
}
