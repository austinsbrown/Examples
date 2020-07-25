`timescale 1ns/1ps
`include "ones_count.v"
`include "ones_count_task.v"
`include "ones_count_function.v"

module ones_count_tb();                                     // test bench for question 1
    parameter   inCount = 32;                               // total number of bits used for the input
    parameter   outCount = $clog2(inCount);                 // total number of bits in the output
    integer     f;                                          // file variable

    wire    [outCount:0]  count;                            // output
    reg     [inCount-1:0]   in_vec;                         // input
    reg     [inCount-1:0]   j;                              // incrementor used in for loop
    reg     [0:inCount]     readValues   [0:inCount-1];     // holds values read from file
    

    ones_count #(.inCount(32)) uut                             
    (
        .count(count),
        .in_vec(in_vec)
    );

    initial
    begin
        $readmemh("input.txt", readValues);                 // read file for inputs
        f = $fopen("output1.txt","w");                      // open file
        $dumpfile("dump.vcd");                              // dump info for simulator
        $dumpvars(0, ones_count_tb);

        for(j=0; j<16; j++)                                 // iterate through read values
        begin
            in_vec = readValues[j];
            #10;
            $fwrite(f,"%d\n",count);                        // write output to file
        end
        #10;
        $fclose(f);                                         // close the file
    end
endmodule
/*
module ones_count_task_tb();                                // test bench for quastion 2
    parameter inCount = 32;                                 // total number of bits used for the input
    parameter outCount = $clog2(inCount);                   // total number of bits in the output
    integer        f;                                       // file variable

    wire    [outCount:0]  count;                          // output
    reg     [inCount-1:0]   in_vec;                         // input
    reg     [inCount-1:0]   j;                              // incrementor used in for loop
    reg     [0:inCount]     readValues   [0:inCount-1];     // holds values read from file

    ones_count_task #(.inCount(32)) uut                                 
    (
        .count(count),
        .in_vec(in_vec)
    );

    initial
    begin
        $readmemh("input.txt", readValues);                 // read file for inputs
        f = $fopen("output2.txt","w");                       // open file
        $dumpfile("dump.vcd");                              // dump info for simulator
        $dumpvars(0, ones_count_task_tb);

        for(j=0; j<16; j++)                                 // iterate through read values
        begin
            in_vec = readValues[j];
            #10;
            $fwrite(f,"%d\n",count);                        // write output to file
        end
        #10;
        $fclose(f);                                         // close the file
    end
endmodule


module ones_count_function_tb();                            // test bench for quastion 2
    parameter inCount = 32;                                 // total number of bits used for the input
    parameter outCount = $clog2(inCount);                   // total number of bits in the output
    integer        f;                                       // file variable

    wire    [outCount:0]  count;                            // output
    reg     [inCount-1:0]   in_vec;                         // input
    reg     [inCount-1:0]   j;                              // incrementor used in for loop
    reg     [0:inCount]     readValues   [0:inCount-1];     // holds values read from file

    ones_count_function #(.inCount(32)) uut                                 
    (
        .count(count),
        .in_vec(in_vec)
    );

    initial
    begin
        $readmemh("input.txt", readValues);                 // read file for inputs
        f = $fopen("output3.txt","w");                       // open file
        $dumpfile("dump.vcd");                              // dump info for simulator
        $dumpvars(0, ones_count_function_tb);

        for(j=0; j<16; j++)                                 // iterate through read values
        begin
            in_vec = readValues[j];
            #10;
            $fwrite(f,"%d\n",count);                        // write output to file
        end
        #10;
        $fclose(f);                                         // close the file
    end
endmodule
*/