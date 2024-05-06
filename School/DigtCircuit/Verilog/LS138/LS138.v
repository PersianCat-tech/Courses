 module LS138 (
    input wire G2A,
    input wire G2B,
    input wire G1,
    input wire A0,
    input wire A1,
    input wire A2,
    output wire Y7,
    output wire Y6,
    output wire Y5,
    output wire Y4,
    output wire Y3,
    output wire Y2,
    output wire Y1,
    output wire Y0);
wire A0n, A1n, A2n;
wire A0nn, A1nn, A2nn, GEn;
assign A0n = ~A0;
assign A0nn = ~A0n;
assign A1n = ~A1;
assign A1nn = ~A1n;
assign A2n = ~A2;
assign A2nn = ~A2n;
assign GEn = G1 & (~G2A) & (~G2B);

assign Y0 = ~(GEn & A2n & A1n & A0n);
assign Y1 = ~(GEn & A2n & A1n & A0nn);
assign Y2 = ~(GEn & A2n & A1nn & A0n);
assign Y3 = ~(GEn & A2n & A1nn & A0nn);
assign Y4 = ~(GEn & A2nn & A1n & A0n);
assign Y5 = ~(GEn & A2nn & A1n & A0nn);
assign Y6 = ~(GEn & A2nn & A1nn & A0n);
assign Y7 = ~(GEn & A2nn & A1nn & A0nn);
 endmodule