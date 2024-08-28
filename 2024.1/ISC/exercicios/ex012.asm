# questionario 1
.data
	number: .space 30
	
.text
	# read string
	li a7, 8
	la a0, number
	li a1, 30
	ecall
	
	# acha ultimo digito
	la t0, number
	# checa se o numero digitado for 0(caso de teste 000)
	li t3, 1
	loop:
		lb t1, 0(t0)
		beqz t1, exit
		li t2, '\n'
		beq t1, t2, exit
		li t2, '0'
		beq  t1, t2, continue
		li t3, 0
		continue:
		addi t0, t0, 1
		j loop
		
	exit:
	addi t0, t0, -1
	
	# print digitos
	la t2, number
	loop1:
		blt t0, t2, exit2
		
		# print char
		li a7, 11
		lb a0, 0(t0)
		ecall
		
		bgtz t3, exit2
		
		addi t0, t0, -1
		j loop1
	exit2:
	
	# exit
	li a7, 10
	ecall
	