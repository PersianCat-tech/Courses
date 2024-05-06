module encoder4_2(
    input wire A0,
    input wire A1,
    input wire A2,
    input wire A3,
    output reg Y0,
    output reg Y1,
    output reg E0);
always @(A0, A1, A2, A3) begin
    if(A3) {Y0, Y1, E0} = 3'b111;
    else if(A2) {Y0, Y1, E0} = 3'b101;
    else if(A1) {Y0, Y1, E0} = 3'b011;
    else if(A0) {Y0, Y1, E0} = 3'b001;
    else  {Y0, Y1, E0} = 3'b000;   
end
endmodule