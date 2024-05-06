module half_adder (
    input Ai,
    input Bi,
    output Si,
    output Ci);
    assign Si = Ai ^ Bi;
    assign Ci = Ai & Bi;    
endmodule

module full_adder(
    input A,
    input B,
    input Cin,
    output S,
    output Cout);
wire C0, A0, C1;
assign Cout = C0 | C1;
half_adder u0(
    .Ai(A),                              
    .Bi(B),
    .Si(A0),
    .Ci(C0));
half_adder u1(
    .Ai(A0),
    .Bi(Cin),
    .Si(S),
    .Ci(C1));
endmodule