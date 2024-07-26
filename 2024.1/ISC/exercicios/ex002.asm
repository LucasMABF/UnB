# laboratorio
.data
	STR: .string "Digite um numero: "
	PAR: .string " eh par!"
	IMPAR: .string " eh impar!"
	# 39 bytes de data

.include "../MACROSv24.s"

.text #  0x198C -> 6540 bytes de programa

	# print string
	li a7,104
	la a0, STR
	li a1, 10
	li a2, 10
	li a3, 0xFF
	li a4, 0
	ecall
	
	
	# read int into s0
	li a7, 105
	ecall
	mv s0, a0
	
	# print int
	li a7,101
	mv a0, s0
	li a1, 10
	li a2, 50
	li a3, 0xFF
	ecall
	
	
	# checa se par
	li t1,2
	rem s1,s0,t1
	
	# coloca endereco da string e a cor do retangulo
	# dependendo se eh par ou impar
	beq s1,zero,Ehpar
	la a0,IMPAR
	li t0 0xC0
	j Mostra
	Ehpar: la a0,PAR
	li t0, 0x07
	
	# printa na tela se eh par ou impar
	Mostra:
	li a7, 104
	li a1, 36
	li a2, 50
	li a3, 0xFF
	li a4, 0
	
	ecall
	
	# printa o retangulo
	li a7, 147
	li a0, 5
	li a1, 40
	li a2, 120
	li a3, 40
	mv a4, t0
	li a5, 0
	ecall
	
	li a0, 5
	li a1, 40
	li a2, 5
	li a3, 65
	ecall
	
	li a0, 5
	li a1, 65
	li a2, 120
	li a3, 65
	ecall
	
	li a0, 120
	li a1, 40
	li a2, 120
	li a3, 65
	ecall
	
	# exit
	li a7,10
	ecall

.include "../SYSTEMv24.s"
