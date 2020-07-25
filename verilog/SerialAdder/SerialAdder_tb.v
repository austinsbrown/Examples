`timescale 1ns/100 ps
`include "moore.v"

module moore_tb();
wire OUT;
wire [1:0] STATE;
reg A, B, clk = 0;

moore uut
(
    .OUT(OUT),
    .STATE(STATE),
    .A(A),
    .B(B),
    .clk(clk)
);

initial
begin

    $dumpfile("dump.vcd");
    $dumpvars(0, moore_tb);

    A = 0;
    B = 0;
    #10;
    
    A = 0;
    B = 1;
    #10;

    A = 1;
    B = 0;
    #10;

    A = 0;
    B = 0;
    #10;

    A = 1;
    B = 1;
    #10;

    A = 0;
    B = 1;
    #10;

    A = 0;
    B = 0;
    #10;

    A = 1;
    B = 1;
    #10;

    A = 1;
    B = 1;
    #10;

    A = 1;
    B = 1;
    #10;

    A = 1;
    B = 0;
    #10;

    A = 1;
    B = 1;
    #10;

    A = 0;
    B = 0;
    #10;
end

always
    #5  clk = ! clk; 

initial 
    #150  $finish; 
endmodule