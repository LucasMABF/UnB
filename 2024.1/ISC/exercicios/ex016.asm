# questionario 2
.data
	sim: .string "SIM"
	nao: .string "NAO"

.text
	# read int s0
	li a7, 5
	ecall
	mv s0, a0
	
	andi t0, s0, 3
	
	beqz t0, divisivel4
	
	nao_divisivel4:
		la a0, nao
		j exit
	
	divisivel4:
		la a0, sim
		
	exit:
	# print
	li a7, 4
	ecall
	
	# exit
	li a7, 10
	ecall
	
