module moore(A, B, OUT, STATE, clk); 
    input       A, B, clk;                                  // inputs to add             
    output reg  OUT;                                        // sum of the inputs
    parameter   CARRY = 0;                                  // carry bit
    output reg  [1:0] STATE = 0;                            // current state

    always @(posedge clk) 
    begin
        if(STATE == 0)                                      // in state 0
        begin
            if(A ^ B)                                       // if one of the inputs is one
            begin
                STATE = 1;                                  // transition to state 1
            end

            else if(A & B)                                  // if both inputs are 1
            begin
                STATE = 2;                                  // transition to state 2
            end
        end

        else if (STATE == 1)
        begin
            if(!A & !B)                                     // both inputs are 0
            begin
                STATE = 0;
            end

            else if(A & B)                                  // both inputs are 1
            begin
                STATE = 2;                                  // transition to state 2
            end
        end

        else if (STATE == 2)                                // if the current state is 2
        begin
            if(!A & !B)                                     // both inputs are 0
            begin
                STATE = 1;                                  // tranistion to state 1
            end

            else if(A & B)                                  // both inputs are 1
            begin
                STATE = 3;                                  // tranition to state 3
            end
        end

        else if (STATE == 3)                                // current state is 3
        begin
            if(!A & !B)                                     // if both inputs are 0
            begin
                STATE = 1;                                  // go to state 1
            end

            if(A ^ B)                                       // if one of the inputs is 1
            begin
                STATE = 2;                                  // go to state 2
            end
        end

        if(STATE == 0)
            OUT = 0;

        else if(STATE == 1)
            OUT = 1;

        else if(STATE == 2)
            OUT = 0;

        else if(STATE == 3)
            OUT = 1;
    end
endmodule
