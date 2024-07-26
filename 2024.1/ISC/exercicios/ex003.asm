# lista
.data
	INPUT: .string "Digite um numero: "
	MESSAGE: .string "Os fatores primos de ", " sao:\n"
	.align 2
	PRIMES:  .space 256
	FACTORS:  .space 256

.text
	# print input prompt
	li a7, 4
	la a0, INPUT
	ecall

	# Read int input into s0
	li a7, 5
	ecall
	mv s0,  a0
	
	# call GET_PRIMES(a0, a1, a2) -> a0
	la a1, PRIMES
	li a2, 64
	jal GET_PRIMES
	
	# call GET_FACTORS(a0, a1, a2, a3, a4) -> a0
	mv a2, a0
	mv a0, s0
	la a3, FACTORS
	li a4, 64
	jal GET_FACTORS
	mv s1, a0
	
	# print mensagem antes dos fatores
	li a7, 4
	la a0, MESSAGE
	ecall
	li a7, 1
	mv a0, s0
	ecall
	li a7, 4
	la a0, MESSAGE
	addi a0, a0, 22
	ecall
	
	# print fatores
	li t0, 0
	la t2, FACTORS
	LOOP3:
		bge t0, s1, EXIT3
		
		slli t1, t0, 2
		add t1, t1, t2
		lw a0, (t1)
		
		li a7, 1
		ecall
		li a0, '\n'
		li a7, 11
		ecall
		
		addi t0, t0, 1
		
		j LOOP3
	
	EXIT3:
	
	# exit
	li a7, 10
	ecall

# get_primes(a0, a1, a2) -> a0
# funcao que preenche uma lista com numeros primos
# ate um numero maximo
# para ate passar do numero maximo ou acabar o espaco da lista
# a0 -> procura ate esse numero
# a1 -> endereco da lista
# a2 -> tamanho da lista
# retorna a0 -> numeros primos encontrados
GET_PRIMES: 
	li t0, 1 # primes to test
	li t1, 0 # list index
	LOOP:
		bge t1, a2, EXIT
		addi t0, t0, 1
		bgtu  t0, a0, EXIT
		
		
		# loop variable through all list
		li t3, 0
		li t2, 1 # prime = true
		LOOP1:
			bge t3, t1, EXIT1
			
			slli t4, t3, 2 # * 4 word
			add t4, a1, t4
			lw t5, (t4)
			remu t6, t0, t5
			
			addi t3, t3, 1
			
			bnez t6, LOOP1
			li t2, 0
			
		EXIT1:
		
		beqz t2, LOOP
		
		# add prime
		mv t4, t1
		slli  t4, t4, 2 # * 4 word
		add t4, t4, a1
		sw t0, (t4)
		addi t1, t1, 1

		
		j LOOP
		
	EXIT:
	# numeros escritos
	mv a0, t1
	ret


# get_factors(a0, a1, a2, a3, a4) -> a0
# retorna os fatores primos de um numero dada uma lista de primos
# a0 -> numero a ser fatorado
# a1 -> endereco da lista de primos
# a2 -> tamanho da lista de primos
# a3 -> endereco para escrever fatores
# a4 -> maximo para escrever, tamanho lista de fatores
# retorna a0 -> numero de fatores encontrados
GET_FACTORS:
	li t0, 0 # index read
	li t2, 0 # index write
	# loop na lista de primos
	LOOP2:
		bge t2, a4, EXIT2
		bge t0, a2, EXIT2
		
		slli t1, t0, 2 # * 4 word
		add t1, t1, a1
		lw t3, (t1)
		
		addi t0, t0, 1
		
		rem t4, a0, t3
		# testa se divisivel
		bnez t4, LOOP2
		
		# adiciona fator
		slli t1, t2, 2 # * 4 word
		add t1, t1, a3
		sw t3, (t1)
		
		addi t2, t2, 1
		
		j LOOP2
	EXIT2:
		# numeros escritos
		mv a0, t2
		ret 
