`timescale 10ps/1ps
module voter_tb;
reg A, B, C;
wire F;
voter DUT(
    .A(A),
    .B(B),
    .C(C),
    .F(F)
);
reg [2:0] i;
initial begin
    for(i = 0; i <= 7; i = i+1)
    begin
        {A, B, C} = i; #1;
    end
end

initial begin
    $dumpfile("voter.vcd");
    $dumpvars(0, voter_tb);
    #20 $stop;
end
endmodule