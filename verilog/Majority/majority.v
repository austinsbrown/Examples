module majority
(
    input  [7:0] a,
    input  [7:0] b,
    input  [7:0] c,
    output reg [7:0] majority
);
    always @(a|b|c) 
    begin
        majority = (a & b) | (a & c) | (b & c);
    end
endmodule