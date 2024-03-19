// By John Bagshaw

`define DATA_WIDTH 16
`define COEF_WIDTH 16
`define NUM_TAPS 32
`define DECISION_DELAY 32

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

module dfe_equalizer (
    input wire signed [DATA_WIDTH-1:0] input_sample,
    input wire signed [DATA_WIDTH-1:0] decision_symbols [DECISION_DELAY-1:0],
    output reg signed [DATA_WIDTH-1:0] output_sample
);

reg signed [DATA_WIDTH-1:0] filtered_output;
reg signed [DATA_WIDTH-1:0] decision_feedback;
reg signed [COEF_WIDTH-1:0] coefficients [NUM_TAPS-1:0];

integer i;

// Compute filter output using the current input sample and equalizer filter coefficients
fir_filter filter (.input(input_sample), .coefficients(coefficients), .output(filtered_output));

// Perform decision feedback using previous decision symbols
always @* begin
    decision_feedback = 0;
    for (i = 0; i < DECISION_DELAY; i = i + 1) begin
        decision_feedback = decision_feedback + decision_symbols[i] * coefficients[i];
    end
end

// Output equalized sample by subtracting decision feedback from filtered output
always @* begin
    output_sample = filtered_output - decision_feedback;
end

endmodule