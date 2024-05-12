// By John Bagshaw

`timescale 1ns / 1ps
module tb_crc_compute();

    reg clk, reset;
    reg [31:0] data_in;
    reg [5:0] CRC_polynomial;
    wire [5:0] CRC_out;

    crc_compute uut (
        .clk(clk),
        .reset(reset),
        .data_in(data_in),
        .CRC_polynomial(CRC_polynomial),
        .CRC_out(CRC_out)
    );

    // Clock generation
    always #10 clk = ~clk;

    initial begin
        clk = 0; reset = 0;
        #20; reset = 1;
        data_in = 32'hBBBBDDDD; CRC_polynomial = 6'b100001;
        #200; data_in = 32'hDDDDBBBB;
        #200; $finish;
    end
endmodule
