`timescale 1ns/10ps
module LS74_tb;
reg CLR, SET, CP, D;
wire Q, Qn;
LS74 DUT(
    .CLR(CLR),
    .SET(SET),
    .CP(CP),
    .D(D),
    .Q(Q),
    .Qn(Qn));
initial begin
    CLR = 1'b1; SET = 1'b1; CP = 1'b0; D = 1'b0;
#10 CLR = 1'b1; SET = 1'b1; CP = 1'b1; D = 1'b1;
#10 CLR = 1'b1; SET = 1'b1; CP = 1'b0; D = 1'b1;
#10 CLR = 1'b1; SET = 1'b1; CP = 1'b1; D = 1'b1;
#10 CLR = 1'b1; SET = 1'b1; CP = 1'b0; D = 1'b0;
#10 CLR = 1'b1; SET = 1'b1; CP = 1'b1; D = 1'b0;
#10 CLR = 1'b1; SET = 1'b1; CP = 1'b0; D = 1'b0;
#10 CLR = 1'b1; SET = 1'b1; CP = 1'b1; D = 1'b0;
#10 CLR = 1'b1; SET = 1'b1; CP = 1'b0; D = 1'b0;
end

initial begin
    $dumpfile("LS74_tb.vcd");
    $dumpvars(0, LS74_tb);
    #90 $stop;
end
endmodule