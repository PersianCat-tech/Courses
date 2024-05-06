`timescale 1ns/100ps
module LS138_tb;
reg G1, G2A, G2B, A2, A1, A0;
wire Y0, Y1, Y2, Y3, Y4, Y5, Y6, Y7;
LS138 DUT(
    .G1(G1),
    .G2A(G2A),
    .G2B(G2B),
    .A2(A2),
    .A1(A1),
    .A0(A0),
    .Y0(Y0),
    .Y1(Y1),
    .Y2(Y2),
    .Y3(Y3),
    .Y4(Y4),
    .Y5(Y5),
    .Y6(Y6),
    .Y7(Y7));
initial begin
    G1 = 1; G2A = 0; G2B = 0; A2 = 0; A1 = 0; A0 = 0;
#10 G1 = 1; G2A = 0; G2B = 0; A2 = 0; A1 = 0; A0 = 1;
#10 G1 = 1; G2A = 0; G2B = 0; A2 = 0; A1 = 1; A0 = 0;
#10 G1 = 1; G2A = 0; G2B = 0; A2 = 0; A1 = 1; A0 = 1;
#10 G1 = 1; G2A = 0; G2B = 0; A2 = 1; A1 = 0; A0 = 0;
#10 G1 = 1; G2A = 0; G2B = 0; A2 = 1; A1 = 0; A0 = 1;
#10 G1 = 1; G2A = 0; G2B = 0; A2 = 1; A1 = 1; A0 = 0;
#10 G1 = 1; G2A = 0; G2B = 0; A2 = 1; A1 = 1; A0 = 1;
end
initial begin
    $dumpfile("LS138.vcd");
    $dumpvars(0, LS138_tb);
    #80 $stop;
end
endmodule