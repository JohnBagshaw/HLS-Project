#include "ap_int.h"

#define NUM_TAPS  32  // Number of taps for the adaptive filter
#define DATA_WIDTH 16  // Data width of input and output samples
#define COEF_WIDTH 16  // Coefficient width for filter coefficients
#define STEP_SIZE 0.01  // Step size parameter for LMS algorithm

typedef ap_fixed<DATA_WIDTH,1> data_t;  // Define data type for input and output samples
typedef ap_fixed<COEF_WIDTH,1> coef_t;  // Define data type for filter coefficients

// FIR filter module
void fir_filter(data_t input, coef_t coefficients[NUM_TAPS], data_t& output) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=input
#pragma HLS INTERFACE ap_none port=output
#pragma HLS ARRAY_PARTITION variable=coefficients complete dim=1

    static data_t shift_register[NUM_TAPS] = {0};  // Shift register for storing previous input samples
    data_t acc = 0;  // Accumulator for computing the filter output
    
    // Shift input samples into the shift register
    for (int i = NUM_TAPS - 1; i > 0; i--) {
        shift_register[i] = shift_register[i-1];
    }
    shift_register[0] = input;
    
    // Compute filter output using the current input sample and filter coefficients
    for (int i = 0; i < NUM_TAPS; i++) {
        acc += shift_register[i] * coefficients[i];
    }
    
    output = acc;  // Set the output to the filtered result
}

// LMS adaptive filtering function
void lms_adaptive_filter(data_t input_sample, data_t& output_sample) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=input_sample
#pragma HLS INTERFACE ap_none port=output_sample

    // Define adaptive filter coefficients (initialized to zeros)
    static coef_t coefficients[NUM_TAPS] = {0};
    // Desired response (e.g., clean signal)
    static data_t desired_output = 0;  
    
    // Compute filter output using the current input sample and adaptive filter coefficients
    data_t filtered_output;
    fir_filter(input_sample, coefficients, filtered_output);
    
    // Compute error (difference between desired output and filtered output)
    data_t error = desired_output - filtered_output;
    
    // Update filter coefficients using LMS algorithm
    for (int i = 0; i < NUM_TAPS; i++) {
        coefficients[i] += STEP_SIZE * error * input_sample;
    }
    
    // Output filtered output as the result of receive filter
    output_sample = filtered_output;
}