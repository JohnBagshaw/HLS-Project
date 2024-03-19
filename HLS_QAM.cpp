#include "ap_int.h"
#include "math.h"

#define SYMBOLS_PER_BIT 4  // Number of QAM symbols per input bit
#define M_PI 3.14159265358979323846

typedef ap_int<8> data_t;  // Define input data type for modulation and demodulation
typedef ap_fixed<16,1> symbol_t;  // Define output symbol type for modulation and demodulation

// QAM modulation function
void qam_modulation(data_t input_data, symbol_t& i_symbol, symbol_t& q_symbol) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=input_data
#pragma HLS INTERFACE ap_none port=i_symbol
#pragma HLS INTERFACE ap_none port=q_symbol

    // Define QAM constellation points
    symbol_t constellation_points[SYMBOLS_PER_BIT] = {1.0, 3.0, -1.0, -3.0};  // Example for QAM-4
    
    // Map input data bits onto QAM constellation points
    int index = input_data % SYMBOLS_PER_BIT;
    i_symbol = constellation_points[index];
    q_symbol = constellation_points[index];
}

// QAM demodulation function
void qam_demodulation(symbol_t i_received_symbol, symbol_t q_received_symbol, data_t& output_data) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=i_received_symbol
#pragma HLS INTERFACE ap_none port=q_received_symbol
#pragma HLS INTERFACE ap_none port=output_data

    // Define QAM constellation points
    symbol_t constellation_points[SYMBOLS_PER_BIT] = {1.0, 3.0, -1.0, -3.0};  // Example for QAM-4
    
    // Initialize variables to store minimum distance and detected symbol index
    symbol_t min_distance = 9999.0;  // Initialize with a large value
    int detected_symbol_index = 0;
    
    // Compute Euclidean distance between received symbol and each constellation point
    for (int i = 0; i < SYMBOLS_PER_BIT; i++) {
        symbol_t distance = sqrt(pow(i_received_symbol - constellation_points[i], 2) + pow(q_received_symbol - constellation_points[i], 2));
        if (distance < min_distance) {
            min_distance = distance;
            detected_symbol_index = i;
        }
    }
    
    // Output detected symbol index as demodulated data
    output_data = detected_symbol_index;
}