module ones_count_task#(parameter inCount=16)(in_vec, count);
    parameter outCount = $clog2(inCount);       // total number of bits used for output
    
    output reg  [outCount:0]  count;               
    input       [inCount-1:0]   in_vec;       
    reg         [inCount-1:0]   i;  

    always @(in_vec)                                        // if in_vec changes 
    begin
        task_name(in_vec, count);                           // call task_name
    end

    task task_name(input [inCount-1:0] in, output [outCount:0] out);     
        reg [inCount-1:0] i;                                // counter variable
        begin
            out = 0;                                        // set the out variable to 0
            for(i = 0; i < inCount; i++)                    // iterate through the input
            begin
                if(in[i] == 1)                              // if a bit is 1...
                    out++;                                  // increment the out variable
            end
        end
    endtask

endmodule 


