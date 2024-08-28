# questionario 2
.text
	# read int n, s0
	li a7, 5
	ecall
	mv s0, a0
	
	# add space for \n or \0
	addi s0, s0, 1
	
	# allocate memory s1
	li a7, 9
	mv a0, s0
	ecall
	mv s1, a0
	
	# read string into a0 address alocated
	li a7, 8
	mv a1, s0
	ecall
	
	# print string
	li a7, 4
	mv a0, s1
	ecall

	# exit
	li a7, 10
	ecall
	
