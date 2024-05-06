module encoder8_3(
    input A0,
    input A1,
    input A2,
    input A3,
    input A4,
    input A5,
    input A6,
    input A7,
    output Y0,
    output Y1,
    output Y2);
    assign Y0 = ~(A0 & A2 & A4 & A6);
    assign Y1 = ~(A0 & A1 & A4 & A5);
    assign Y2 = ~(A0 & A1 & A2 & A3); 
endmodule