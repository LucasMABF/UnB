# questionario 1
.data
	dobro: .string "Dobro:"
	metade: .string "Metade:"

.text
	# read int s0
	li a7, 5
	ecall
	mv s0, a0
	
	# print string	
	li a7, 4
	la a0, dobro
	ecall
	
	# calcula dobro s1
	slli s1, s0, 1
	
	# print int
	li a7, 1
	mv a0, s1
	ecall
	
	# print \n
	li a7, 11
	li a0, '\n'
	ecall
	# print string
	li a7, 4
	la a0, metade
	ecall
	
	# calcula metade s2
	srai s2, s0, 1
	
	# print int
	li a7, 1
	mv a0, s2
	ecall
	
	# print \n
	li a7, 11
	li a0, '\n'
	ecall
	
	# exit
	li a7, 10
	ecall
