`timescale 10ps/1ps
module encoder4_2_tb;
//Input 
reg  A0, A1, A2, A3;
// output
wire Y0, Y1, E0;
encoder4_2 DUT(
    .A0(A0),
    .A1(A1),
    .A2(A2),
    .A3(A3),
    .Y0(Y0),
    .Y1(Y1),
    .E0(E0));
reg [3:0] i;
initial begin
    for(i = 0; i <= 15; i = i+1)
    begin
        {A0, A1, A2, A3} = i; #1;
    end
end

initial begin
    $dumpfile("encoder4_2.vcd");
    $dumpvars(0, encoder4_2_tb);
    #32 $stop;
end
endmodule