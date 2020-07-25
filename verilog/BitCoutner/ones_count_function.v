module ones_count_function#(parameter inCount=16)(in_vec, count);
   parameter outCount = $clog2(inCount);       // total number of bits used for output

    output reg  [outCount:0]  count;               
    input       [inCount-1:0]   in_vec;  

    always @(in_vec)
    begin
        count = function_name(in_vec);
    end

    function [outCount:0] function_name;
        input   [inCount-1:0]   in;
        reg     [inCount-1:0]   i;
        reg     [outCount:0]    temp;                       // holds output

        begin
            temp = 0;                                       // set the out variable to 0
            for(i = 0; i < inCount; i++)                    // iterate through the input
            begin
                if(in[i] == 1)                              // if a bit is 1...
                    temp++;                                 // increment the out variable
            end
            function_name = temp;
        end
    endfunction

endmodule