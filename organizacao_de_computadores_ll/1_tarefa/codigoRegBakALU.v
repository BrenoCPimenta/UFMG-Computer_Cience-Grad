module main(
  	input [2:0] enderecoA,
  	input [2:0] enderecoB,
  	input [3:0] alucontrol,
  	output [3:0] aluout,
    output zero,
	input clk
);
    wire [2:0] fioA;
    wire [2:0] fioB;
  
  banco instancia_banco_registradores (
    .enderecoA (enderecoA),
    .enderecoB (enderecoB),
    .dadosA (fioA),
    .dadosB (fioB),
    .clk (clk)
  );

  ALU instancia_ALU (
    .alucontrol (alucontrol), 
    .A (fioA),
    .B (fioB), 
    .aluout (aluout), 
    .zero (zero)
  );       
endmodule

module banco(
  input [2:0] enderecoA,
  input [2:0]enderecoB,
  input clk,
  output [2:0] dadosA,
  output [2:0] dadosB
);
  
  reg [2:0] banco_registradores [0:7];
  initial 
  	begin
      banco_registradores[0] <= 3'b000;
      banco_registradores[1] <= 3'b001;
      banco_registradores[2] <= 3'b010;
      banco_registradores[3] <= 3'b011;
      banco_registradores[4] <= 3'b100;
      banco_registradores[5] <= 3'b101;
      banco_registradores[6] <= 3'b110;
      banco_registradores[7] <= 3'b111;
  end
  
  always @(posedge clk) 
    begin
      dadosA <= banco_registradores[enderecoA];
      dadosB <= banco_registradores[enderecoB];
  	end
endmodule 


module ALU(
    input [3:0] alucontrol,
  	input [2:0] A,
  	input [2:0] B,
  	output [3:0] aluout,
    output zero
);
  reg [3:0] aluout;
  assign zero = (aluout == 0);
  always @(alucontrol, A, B) begin
    case (alucontrol)
      0: aluout <= A & B; //AND
      1: aluout <= A | B; //OR
      2: aluout <= A + B; //ADD
      6: aluout <= A - B; //SUB
      7: aluout <= A < B ?4'd1:4'd0;//SLT
      12: aluout <= ~( A | B); //NOR
      default: aluout <= 0;
    endcase
  end
endmodule