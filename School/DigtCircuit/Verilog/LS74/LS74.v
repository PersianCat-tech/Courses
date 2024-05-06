module LS74 (
    input wire CLR,
    input wire SET,
    input wire CP,
    input wire D,
    output wire Q,
    output wire Qn);
//功能定义
wire g3, g4, g5, g6;
assign g6 = ~( CLR &D &g4);
assign g5 = ~( SET &g6 & g3);
assign g3 = ~( CLR &CP &g5);
assign g4 = ~( g3 &CP &g6);
assign Q = ~( SET &Qn &g3);
assign Qn = ~( CLR &Q &g4);
endmodule