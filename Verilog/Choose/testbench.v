`include "choose.v"
`timescale 1ns/1ps

module choose_tb();
    reg  [7:0] a;
    reg  [7:0] b;
    reg  [7:0] c;
    wire [7:0] chosen;

    choose uut
    (
        a,
        b,
        c,
        chosen
    );

    initial
    begin

        $dumpfile("dump.vcd");
        $dumpvars(0, choose_tb);   

        #1;
        a = 8'b00001100;
        b = 8'b00001110;
        c = 8'b00001000;

        #1;
        a = 255;
        b = 0;
        c = 255;
        
        #1;
        a = 0;
        b = 6;
        c = 100;

        #1;
    end            
endmodule