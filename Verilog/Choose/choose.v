module choose
(
    input  [7:0] a,
    input  [7:0] b,
    input  [7:0] c,
    output reg [7:0] chosen
);
    always @(a|b|c) 
    begin
        chosen = (a & b) | (~a & c);
    end
endmodule