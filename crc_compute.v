//By John Bagshaw
module crc_compute(
    input clk,
    input reset,
    input [31:0] data_in,
    input [5:0] CRC_polynomial,
    output reg [5:0] CRC_out
);
    reg [31:0] data_shift;
    reg [5:0] crc_reg;

    always @(posedge clk or negedge reset) begin
        if (!reset) begin
            crc_reg <= 6'b0;
            data_shift <= data_in;
        end else begin
            data_shift <= {data_shift[30:0], 1'b0};
            if (crc_reg[5] ^ data_shift[31]) begin
                crc_reg <= (crc_reg << 1) ^ CRC_polynomial;
            end else begin
                crc_reg <= crc_reg << 1;
            }
        end
        CRC_out <= crc_reg;
    end
endmodule
