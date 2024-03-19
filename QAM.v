// By John Bagshaw
`timescale 1ns / 1ps

module qam_modulation_demodulation (
    input wire signed [7:0] input_data,
    output reg signed [15:0] i_symbol,
    output reg signed [15:0] q_symbol,
    input wire signed [15:0] i_received_symbol,
    input wire signed [15:0] q_received_symbol,
    output reg signed [7:0] output_data
);

// Define QAM constellation points
reg signed [15:0] constellation_points [3:0];

// Initialize QAM constellation points
initial begin
    constellation_points[0] = 16'd32768;
    constellation_points[1] = 16'd49152;
    constellation_points[2] = 16'd-32768;
    constellation_points[3] = 16'd-49152;
end

// QAM modulation function
always @* begin
    i_symbol = constellation_points[input_data % 4];
    q_symbol = constellation_points[input_data % 4];
end

// QAM demodulation function
always @* begin
    reg signed [15:0] distance;
    reg [7:0] detected_symbol_index;
    reg signed [15:0] min_distance = 16'd9999;

    // Compute Euclidean distance between received symbol and each constellation point
    for (int i = 0; i < 4; i = i + 1) begin
        distance = sqrt((i_received_symbol - constellation_points[i]) ** 2 + (q_received_symbol - constellation_points[i]) ** 2);
        if (distance < min_distance) begin
            min_distance = distance;
            detected_symbol_index = i;
        end
    end

    // Output detected symbol index as demodulated data
    output_data = detected_symbol_index;
end

endmodule