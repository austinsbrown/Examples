module ones_count #(parameter inCount=16)(in_vec, count);
    parameter outCount = $clog2(inCount);       // total number of bits used for output
    
    output reg  [outCount:0]  count;               
    input       [inCount-1:0]   in_vec;       
    reg         [inCount-1:0]   i;          

    always @(in_vec)                            // look for changes in the input
    begin
        count = 0;                              // set the count to 0
        for(i = 0; i < inCount; i++)            // iterate through input one bit at a time
        begin
            if(in_vec[i] == 1)                  // if the bit is one, increment count
                count++;
        end
    end
endmodule