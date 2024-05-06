`timescale 10ps/1ps
module encoder8_3_tb;
reg [7:0] A;
wire Y0, Y1, Y2;
reg [2:0] i;
encoder8_3 DUT(
    .A0(A[0]),
    .A1(A[1]),
    .A2(A[2]),
    .A3(A[3]),
    .A4(A[4]),
    .A5(A[5]),
    .A6(A[6]),
    .A7(A[7]),
    .Y0(Y0),
    .Y1(Y1),
    .Y2(Y2));
initial begin
    for(i = 0; i <= 7; i = i+1)
    begin
        A = 8'b11111111;
        A[i] = 0; #1;
    end
end

initial begin
    $dumpfile("encoder8_3.vcd");
    $dumpvars(0, encoder8_3_tb);
    #20 $stop;
end
endmodule