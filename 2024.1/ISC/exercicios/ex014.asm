# questionario 2
.data
	corre: .string "Corre, Gui!"
	poxa: .string "Poxa, Gui."

.text
	# read s0, v
	li a7, 5
	ecall
	mv s0, a0
	
	# read s1, t
	ecall 
	mv s1, a0
	
	# read s2, d
	ecall
	mv s2, a0
	
	div t0, s2, s0
	
	
	ble t0, s1, sim
	nao:
		la a0, poxa
		j print
	sim:
		la a0, corre
	
	print:
	li a7, 4
	ecall
	
	# exit
	li a7, 10
	ecall
	