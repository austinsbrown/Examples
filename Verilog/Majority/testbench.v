`include "majority.v"
`timescale 1 ns/1 ps

module majority_tb();
    reg  [7:0] a;
    reg  [7:0] b;
    reg  [7:0] c;
    wire [7:0] majority;

    majority sim(a, b, c, majority);

    initial 
    begin
        $dumpfile("dump.vcd");
        $dumpvars(0, majority_tb);  

        #1;
        a=2;
        b = 255;
        c = 144;

        #1;
    end
endmodule