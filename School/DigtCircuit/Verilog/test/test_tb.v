`timescale 100ps/1ps
module full_adder_tb;
// Inputs
    reg A, B, Cin;
//Outputs
    wire S, Cout;
//Instantiate
full_adder DUT(
.A(A),
.B(B),
.Cin(Cin),
.S(S),
.Cout(Cout));
reg [2:0] i;
initial begin
    for (i = 0; i <= 7; i = i+1)
    begin
        {A, B, Cin} = i; #1;
    end
end

initial 
	begin
		$dumpfile("test.vcd");
		$dumpvars(0,full_adder_tb);
		#20 $stop;
	end

endmodule