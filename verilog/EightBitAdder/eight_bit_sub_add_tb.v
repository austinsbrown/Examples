`timescale 1s/100ms
`include "eight_bit_sub_add.v"

module eight_bit_sub_add_tb();
wire B_COUT;
wire [7:0] D_S;
reg B_CIN, SUB_ADD;
reg [7:0] A, B;

eight_bit_sub_add uut
(
    .B_CIN(B_CIN),
    .B_COUT(B_COUT),
    .D_S(D_S),
    .A(A),
    .B(B),
    .SUB_ADD(SUB_ADD)
);

initial
begin

    //$monitor(SUB_ADD, B_CIN, A, B, B_COUT, D_S);

    $dumpfile("dump.vcd");
    $dumpvars(0, eight_bit_sub_add_tb);

    SUB_ADD = 1;
    A = 5;
    B = 2;
    B_CIN = 0;
    #1;

    SUB_ADD = 0;
    A = 200;
    B = 200;
    #1;

    A = 10;
    B = 2;
    #1;

end
endmodule
