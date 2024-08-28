# questionario 3
.data
	esperar_str: .string "\nMelhor esperar..."
	mais_dinheiro_str: .string "\nD� pra juntar mais dinheiro"

.text
	# ler or�amento
	li a7, 5
	ecall
	mv s0, a0
	
	li s1, 0 # melhor preco
	li s2, 0 # melhor avaliacao
	li s3, 0 # todas no orcamento menor ou igual a 3
	li s4, 0 # juntar mais dinheiro
	li t0, 0 # count
	li t1, 5 # max
	loop:
		bge t0, t1, exit
		
		# ler preco
		li a7, 5
		ecall
		mv t2, a0
		
		# ler avaliacao
		li a7, 5
		ecall
		 mv t3, a0
		
		addi t0, t0, 1 # i++
		
		#  testa se avaliacao 10 e preco maior 50
		li t4, 10
		bne t3, t4, fimteste
		
		mv t4, s0
		addi t4, t4, 50
		bgt t2, t4, fimteste
		li s4, 1
		
		fimteste:
		# testa se avaliacao menor 3, e no orcamento
		bgt t2, s0, loop
		li s3, 1 # existe alguma no orcamento
		li t4, 3
		ble t3, t4, fimteste1
		li s3, 0
		
		fimteste1:
		# checa se avaliacao for igual o menor preco
		bne t3, s2, fimteste2
		bge t2, s0, loop
		mv s1, t2
		j loop
		
		fimteste2:
		# checa se avaliacao melhor e dentro do orcamento
		blt t3, s2, loop
		bgt t2, s0, loop
		
		mv s1, t2
		mv s2, t3
		
		j loop
	
	exit:
	li a7, 1
	mv a0, s1
	ecall
	bnez s4, mais_dinheiro
	beqz s3, end
	
	li a7, 4
	la a0, esperar_str
	ecall
	j end
	
	mais_dinheiro:
	li a7, 4
	la a0, mais_dinheiro_str
	ecall

	end:
	
	li a7, 10
	ecall
