# questionario 3
.data
	ufa: .string "Ufa!"
	poxa: .string "Poxa..."

.text
	# ler notas
	li a7, 5
	ecall
	mv s0, a0
	
	ecall
	mv s1, a0
	
	ecall
	mv s2, a0
	
	# calcula quanto falta
	add s3, s0, s1
	add s3, s3, s2
	li t0, 200
	sub s3, t0, s3

	# checa possiblidade de passar
	bltz s3, passou
	li t0, 100
	bgt s3, t0, nao_passou
	
	# printa resultado
	
		li a7, 1
		mv a0, s3
		ecall
		j end
	
	passou:
		li a7, 4
		la a0, ufa
		ecall
		j end
	
	nao_passou:
		li a7, 4
		la a0, poxa
		ecall
		j end
	
	
	end:
	li a7, 10
	ecall
