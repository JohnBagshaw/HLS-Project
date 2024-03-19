#include "ap_int.h"

#define NUM_TAPS  10  // Number of taps for the equalizer filter
#define STEP_SIZE 0.01  // Step size parameter for LMS algorithm

typedef ap_fixed<16,1> data_t;  // Define fixed-point data type for input/output samples
typedef ap_fixed<16,1> coef_t;  // Define fixed-point data type for filter coefficients

// FIR filter module
void fir_filter(data_t input, coef_t coefficients[NUM_TAPS], data_t& output) {
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

// LMS equalizer module
void lms_equalizer(data_t input_sample, data_t error, coef_t coefficients[NUM_TAPS]) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=input_sample
#pragma HLS INTERFACE ap_none port=error
#pragma HLS INTERFACE ap_none port=coefficients

    static data_t x[NUM_TAPS] = {0};  // Array to store input samples
    static data_t y;  // Filter output
    static coef_t w[NUM_TAPS] = {0};  // Filter coefficients
    static data_t d = 0;  // Desired output (error signal)

    // Update filter output
    fir_filter(input_sample, w, y);
    
    // Compute error signal (difference between desired output and actual output)
    error = d - y;
    
    // Update filter coefficients using LMS algorithm
    for (int i = 0; i < NUM_TAPS; i++) {
        w[i] = w[i] + STEP_SIZE * error * x[i];
    }
    
    // Shift input samples in the delay line
    for (int i = NUM_TAPS - 1; i > 0; i--) {
        x[i] = x[i-1];
    }
    x[0] = input_sample;
}