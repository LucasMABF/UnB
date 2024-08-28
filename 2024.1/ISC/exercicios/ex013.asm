# questionario 1
.text
	# read int s0
	li a7, 5
	ecall
	mv s0, a0
	
	# read int s1
	ecall
	mv s1, a0
	
	# maior em s0
	bgt s0, s1, resto
	# swap
	mv t1, s0
	mv s0, s1
	mv s1, t1
	
	resto:
	mv t0, s1
	loop:
		rem t1, s0, t0
		rem t2, s1, t0
		addi t0, t0, -1
		bnez t1, loop
		bnez t2, loop
	
	addi t0, t0, 1
	
	# print mdc
	li a7, 1
	mv a0, t0
	ecall
	
	# exit
	li a7, 10
	ecall
