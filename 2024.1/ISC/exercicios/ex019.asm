# questionario 3
.data
	palindromo: .string "� pal�ndromo"
	nao_palindromo: .string "N�o � pal�ndromo"

.text
	# ler quantidade caracteres
	li a7, 5
	ecall
	mv s0, a0
	addi a0, a0, 2
	
	# alocar memoria
	li a7, 9
	ecall
	mv s1, a0
	
	# ler palavra
	li a7, 8
	mv a1, s0
	addi a1, a1, 2
	ecall
	
	# checa se � pal�ndromo
	li t0, 2
	div t0, s0, t0
	
	li t1, 0 # count
	li t6, 1 # palindromo = true
	loop:
		bge t1, t0, eh_palindromo
		
		add t4, s1, t1
		lbu t2, (t4)
		sub t4, s0, t1
		addi t4, t4, -1
		add t4, t4, s1
		lbu t3, (t4)
		
				
		addi t1, t1, 1
		
		beq t2, t3, loop
		
	li t6, 0 # nao
	li a7, 4
	la a0, nao_palindromo
	ecall
	j end
		
	eh_palindromo:
	li a7, 4
	la a0, palindromo
	ecall
	
	end:
	
	li a7, 10
	ecall
