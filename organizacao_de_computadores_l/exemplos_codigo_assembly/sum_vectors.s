.data
  input:.word 7, 8 # User input

.text
main:
  la x6, input
  lw x5, 0(x6) # Loading first value
  lw x7, 4(x6) # Loading second value
  jal x1, sum # Calling sum and saving the next address to be executed when we return from sum
  addi a1, x10, 0 # a1 will stores the result
  addi a0, x0, 1 # Making ecall be the output
  ecall # Printing the result
  jal  zero, end

sum:
  add  a0, x5, x7
  jalr x0, 0(x1) # Going back to main
end: