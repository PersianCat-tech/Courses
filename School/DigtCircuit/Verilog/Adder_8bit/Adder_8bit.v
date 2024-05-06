module FullAdder (
    input A, // 第一个输入位
    input B, // 第二个输入位
    input Cin, // 进位
    output Sum, // 和
    output Cout // 进位
);

    assign Sum = A ^ B ^ Cin; // 异或操作得到和
    assign Cout = (A & B) | (A & Cin) | (B & Cin); // 进位逻辑

endmodule

module Adder_8bit(
    input [7:0] A, // 第一个加数
    input [7:0] B, // 第二个加数
    output [7:0] Sum, // 和
    output CarryOut // 进位
);

    wire [7:0] c;
    wire [7:0] Carry;

    // 第一个全加器
    FullAdder FA0(.A(A[0]), .B(B[0]), .Cin(1'b0), .Sum(c[0]), .Cout(Carry[0]));
    // 第二个全加器
    FullAdder FA1(.A(A[1]), .B(B[1]), .Cin(Carry[0]), .Sum(c[1]), .Cout(Carry[1]));
    // 第三个全加器
    FullAdder FA2(.A(A[2]), .B(B[2]), .Cin(Carry[1]), .Sum(c[2]), .Cout(Carry[2]));
    // 第四个全加器
    FullAdder FA3(.A(A[3]), .B(B[3]), .Cin(Carry[2]), .Sum(c[3]), .Cout(Carry[3]));
    // 第五个全加器
    FullAdder FA4(.A(A[4]), .B(B[4]), .Cin(Carry[3]), .Sum(c[4]), .Cout(Carry[4]));
    // 第六个全加器
    FullAdder FA5(.A(A[5]), .B(B[5]), .Cin(Carry[4]), .Sum(c[5]), .Cout(Carry[5]));
    // 第七个全加器
    FullAdder FA6(.A(A[6]), .B(B[6]), .Cin(Carry[5]), .Sum(c[6]), .Cout(Carry[6]));
    // 第八个全加器
    FullAdder FA7(.A(A[7]), .B(B[7]), .Cin(Carry[6]), .Sum(c[7]), .Cout(Carry[7]));

    assign Sum = c;
    assign CarryOut = Carry[7];

endmodule
