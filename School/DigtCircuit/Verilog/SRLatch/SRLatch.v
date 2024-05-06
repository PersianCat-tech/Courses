module SRLatch (
    input wire S,
    input wire R,
    output wire Q,
    output wire Qn);
    //功能定义
    assign Q = ~(Qn | R);
    assign Qn = ~(Q | S);
endmodule