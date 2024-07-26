# lista
# b) checa se numero em endereco de memoria 0 eh primo e escreve no endereco 1, 1 ou 0, dependendo se eh primo ou nao
# c) 1
# d) 0
# e) 68 + exit(adicionado) - jump(removido)
.data
	ONE: .word 73
.text
	# a) (modificado para entender melhor)
	# le endereco
	la s0, ONE
	lw a0, (s0)
	
	# retorna a7
	# a7 = 0 se nao e primo
	# a7 = 1 se e primo
	jal PRIMO
	
	# escreve endereco
	sw a7, 4(s0)
	
	# exit
	li a7, 10
	ecall

# checa se numero e primo
# input
# a0 - numero
PRIMO: 
	# pega ultimo bit
	andi t0, a0, 1
	# checa se a0 par
	beqz t0, NAO_PRIMO

	# t3 = a0 // 2
	srli t3, a0, 1

	li t0, 3

	LOOP: 
	
		# checa se a0 divisivel por numeros impares
		rem t1, a0, t0
		beqz t1, NAO_PRIMO

 		addi t0, t0, 2
 
		bltu t0, t3, LOOP
 
 		# retorna 1 se for primo
 		li a7, 1
      	j EXIT
 
 	NAO_PRIMO: 
 		# return 0 se nao for primo
 		li a7, 0
 
 	# return
 	EXIT: 
 		ret
