# lista
.data
	SOMA: .string "Soma = "
	MAIOR: .string "Caractere de maior valor = "

.include "../MACROSv24.s"

.text

	# print strings
	li a7, 104
	la a0, SOMA
	li a1, 40
	li a2, 40
	li a3, 0xFF
	li a4, 0
	ecall
	
	li a7, 104
	la a0, MAIOR
	li a1, 40
	li a2, 70
	li a3, 0xFF
	li a4, 0
	ecall
	
	li s1, 0 # soma
	li s2, 0 # maior
	LOOP:
		
		# print values
		li a7, 101
		mv a0, s1
		li a1, 100
		li a2, 40
		ecall
		
		li a7, 101
		mv a0, s2
		li a1, 270
		li a2, 70
		ecall
		
		# read char
		li a7, 112
		ecall

		# soma
		add s1, s1, a0
		
		# maior
		blt a0, s2, LOOP
		mv s2, a0
		
		j LOOP


.include "../SYSTEMv24.s"
