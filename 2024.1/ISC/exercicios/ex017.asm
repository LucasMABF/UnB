# questionario 2
.text
	# read n s0
	li a7, 5
	ecall
	mv s0, a0
	
	# add space for \n or \0
	addi s0, s0, 1
	
	# allocate memory address s1
	li a7, 9
	mv a0, s0
	ecall
	mv s1, a0

	# read string
	li a7, 8
	mv a1, s0
	ecall
	
	# print characteres
	mv t0, s1
	add t0, t0, s0
	addi t0, t0, -2
	loop1:
		blt t0, s1, exit2
		
		# print char
		li a7, 11
		lb a0, 0(t0)
		ecall
		
		addi t0, t0, -1
		j loop1
	exit2:
	
	# exit
	li a7, 10
	ecall
	