# laboratorio
.data
	STR: .string "Digite um numero: "
	PAR: .string " eh par!"
	IMPAR: .string " eh impar!"

	# 39 bytes de data

.text #  80 bytes de programa

	# print string
	la a0,STR
	li a7,4
	ecall
	
	# read int
	li a7,5
	ecall
	
	
	# print int
	li a7,1
	ecall
	
	
	# checa se par
	li t1,2
	rem t2,a0,t1
	
	# coloca endereco da string
	# dependendo se eh par ou impar
	beq t2,zero,Ehpar
	la a0,IMPAR
	j Mostra
	Ehpar: la a0,PAR
	
	# printa na tela se eh par ou impar
	Mostra: li a7,4
	ecall
	
	# exit
	li a7,10
	ecall
	
