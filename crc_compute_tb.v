`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Jotshaw
// Engineer: John Bagshaw
// 
// Create Date: 05/14/2024 12:51:08 PM
// Design Name: CRC Compute
// Module Name: CRC_compute_tb
// Project Name: 
// Target Devices: Basys3
// Tool Versions: Vivado 2023.1
// Description: 
//////////////////////////////////////////////////////////////////////////////////

module tb_crc_compute;

reg clk;
reg reset;
reg [31:0] data_in;
reg [5:0] CRC_polynomial;
reg tvalid;
wire [5:0] CRC_out;
wire tready;

crc_compute uut (
    .clk(clk),
    .reset(reset),
    .data_in(data_in),
    .CRC_polynomial(CRC_polynomial),
    .tvalid(tvalid),
    .CRC_out(CRC_out),
    .tready(tready)
);

initial begin
    clk = 0;
    forever #5 clk = ~clk;
end

initial begin
    reset = 1'b0; tvalid = 1'b0;
    #10 reset = 1'b1; 
    #10;
    
    data_in = 32'hBBBBDDDD; CRC_polynomial = 6'b100001; tvalid = 1'b1;
    wait(tready == 1'b1);
    tvalid = 1'b0;
    
    #10;
    data_in = 32'hDDDDBBBB; CRC_polynomial = 6'b100001; tvalid = 1'b1;
    wait(tready == 1'b1);
    tvalid = 1'b0;
    
    #10;
    data_in = 32'hDDDDBBBB; CRC_polynomial = 6'b110011; tvalid = 1'b1;
    wait(tready == 1'b1);
    tvalid = 1'b0;
    
    #100 $finish;
end

endmodule
