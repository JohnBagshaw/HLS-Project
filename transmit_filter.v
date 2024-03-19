// By John Bagshaw

`timescale 1ns / 1ps

`define DATA_WIDTH 16
`define COEF_WIDTH 16
`define NUM_TAPS 32

module fir_filter (
    input wire signed [DATA_WIDTH-1:0] input,
    input wire signed [COEF_WIDTH-1:0] coefficients [NUM_TAPS-1:0],
    output reg signed [DATA_WIDTH-1:0] output
);

reg signed [DATA_WIDTH-1:0] shift_register [NUM_TAPS-1:0];
reg signed [DATA_WIDTH-1:0] acc;

integer i;

// Shift input samples into the shift register
always @* begin
    for (i = NUM_TAPS-1; i > 0; i = i - 1) begin
        shift_register[i] = shift_register[i-1];
    end
    shift_register[0] = input;
end

// Compute filter output using the current input sample and filter coefficients
always @* begin
    acc = 0;
    for (i = 0; i < NUM_TAPS; i = i + 1) begin
        acc = acc + shift_register[i] * coefficients[i];
    end
end

// Set the output to the filtered result
always @* begin
    output = acc;
end

endmodule

module transmit_filter (
    input wire signed [DATA_WIDTH-1:0] input_sample,
    output reg signed [DATA_WIDTH-1:0] output_sample
);

reg signed [DATA_WIDTH-1:0] filtered_output;
reg signed [COEF_WIDTH-1:0] coefficients [NUM_TAPS-1:0];

integer i;

// Define FIR filter coefficients to shape the transmitted signal spectrum
initial begin
    coefficients = '{32'b0_001, 32'b0_002, 32'b0_003, 32'b0_004, 32'b0_005, 32'b0_006, 32'b0_007, 32'b0_008,
                     32'b0_009, 32'b0_010, 32'b0_011, 32'b0_012, 32'b0_013, 32'b0_014, 32'b0_015, 32'b0_016,
                     32'b0_017, 32'b0_018, 32'b0_019, 32'b0_020, 32'b0_021, 32'b0_022, 32'b0_023, 32'b0_024,
                     32'b0_025, 32'b0_024, 32'b0_023, 32'b0_022, 32'b0_021, 32'b0_020, 32'b0_019, 32'b0_018 };
end

// Apply FIR filter to input sample to shape the transmitted signal spectrum
fir_filter filter (.input(input_sample), .coefficients(coefficients), .output(filtered_output));

// Output the filtered output
always @* begin
    output_sample = filtered_output;
end

endmodule