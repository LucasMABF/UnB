# lista
.data
	INPUT: .string "Digite seu nome: "
	STR: .ascii "Hello, "
	NOME: .space 22

.include "../MACROSv24.s"

.text
	# print string bitmap
	li a7, 104
	la a0, INPUT
	li a1, 10
	li a2, 10
	li a3, 0xFF
	li a4, 0
	ecall
	
	# read string
	li a7, 108
	la a0, NOME
	li a1, 20
	ecall
	
	# add ! after name
	la t0, NOME
	LOOP:
		lb t1, (t0)
		beqz t1, EXIT
		addi t0, t0, 1
		j LOOP
		
	EXIT:
		li t1, '!'
		sb t1, (t0)
		sb zero, 1(t0)
	
	# print string bitmap
	li a7, 104
	la a0, STR
	li a1, 10
	li a2, 30
	li a3, 0xFF
	li a4, 0
	ecall
	
	# exit
	li a7, 10
	ecall
	
	
.include "../SYSTEMv24.s"
	
