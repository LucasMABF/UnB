# lista
.include "../MACROSv24.s"

.text
	# counter
	li t1, 1
	LOOP:
		# t1 < 1000
		li t0, 1000
		bgt t1, t0, EXIT
		
		# print in bitmap
		li a7, 101
		mv a0, t1
		li a1, 160
		li a2, 120
		li a3, 0xFF
		li a4, 0
		ecall
		
		li a0,50 # pausa de 50m segundos
	  	li a7,32
	  	ecall
		
		# t1++
		addi t1, t1, 1
		j LOOP
		
	EXIT:
	li a7, 10
	ecall
	
	
.include "../SYSTEMv24.s"
