
//////////////////////////////////////////////////////////////////////////////////
// Company: Jotshaw
// Engineer: John Bagshaw
// 
// Create Date: 05/14/2024 12:39:28 PM
// Design Name: CRC Compute
// Module Name: CRC_compute
// Project Name: 
// Target Devices: Basys3
// Tool Versions: Vivado 2023.1
//////////////////////////////////////////////////////////////////////////////////

`timescale 1ns / 1ps
module crc_compute(
    input clk,
    input reset,
    input [31:0] data_in,
    input [5:0] CRC_polynomial,
    input tvalid,   // Valid input signal
    output reg [5:0] CRC_out,
    output reg tready  // Ready to receive data
);

reg [5:0] crc_reg;
integer i;

always @(posedge clk or negedge reset) begin
    if (!reset) begin
        crc_reg <= 6'b0;
        CRC_out <= 6'b0;
        tready <= 1'b0;
    end else if (tvalid && !tready) begin
        crc_reg <= 6'b111111;  // All bits set for initial condition
        for (i = 0; i < 32; i = i + 1) begin
            if (crc_reg[5] ^ data_in[i]) begin
                crc_reg <= (crc_reg << 1) ^ CRC_polynomial;
            end else begin
                crc_reg <= crc_reg << 1;
            end
        end
        CRC_out <= crc_reg;
        tready <= 1'b1;  // Data processed
    end else begin
        tready <= 1'b0;  // Not ready for new data until the next cycle
    end
end

endmodule
