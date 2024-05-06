`timescale 10ps/1ps
module Adder_8bits_tb;
    // 8 位加法器的测试模块
    reg [7:0] A; // 第一个加数
    reg [7:0] B; // 第二个加数
    wire [7:0] Sum; // 和
    wire CarryOut; // 进位

    // 实例化被测试的加法器模块
    Adder_8bit DUT(
        .A(A),
        .B(B),
        .Sum(Sum),
        .CarryOut(CarryOut));

    // 初始化输入
initial begin
    A = 8'b11001010;
    B = 8'b1100111;
    #10; 
end
initial begin
    $dumpfile("Adder_8bits_tb.vcd");
    $dumpvars(0, Adder_8bits_tb);
    #32 $stop;
end
endmodule
