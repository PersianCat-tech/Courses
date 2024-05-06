`timescale 1ns/10ps
module SRLatch_tb;
reg S, R;
wire Q, Qn;
SRLatch DUT(
    .S(S),
    .R(R),
    .Q(Q),
    .Qn(Qn));
initial begin
    S = 1'b1; R = 1'b0;
#10 S = 1'b0; R = 1'b1;
#10 S = 1'b1; R = 1'b0;
#10 S = 1'b0; R = 1'b0;
#10 S = 1'b1; R = 1'b1;
#10 S = 1'b1; R = 1'b0;
#10 $stop;
end

initial begin
    $dumpfile("SRLatch_tb.vcd");
    $dumpvars(0, SRLatch_tb);
    #120 $stop;
end
endmodule