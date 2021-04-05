.data
  input:.word 8 # User input

.text
main:
  la x6, input
  lw x5, 0(x6) # Loading first value
  jal x1, evenorodd # Calling evenorodd and saving the next address to be executed when we return from evernorodd
  addi a1, x10, 0 # a1 will stores the result
  addi a0, x0, 1 # Making ecall be the output
  ecall # Printing the result
  jal  zero, end

evenorodd:
  addi t1, x0, 2
  rem  a0, t0, t1 # a0 <-t0 mod t1 
  jalr x0, 0(x1) # Going back to main

end: