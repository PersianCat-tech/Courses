module voter (
    A, B, C, F
);
    input A, B, C;
    output F;
    wire h1, h2;
    assign h1 = ~(A&B);
    assign h2 = ~(A&C);
    assign F = ~(h1&h2);
endmodule