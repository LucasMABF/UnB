# lista
.text

	# a) jr t0
	la t0, NEXT
	jalr zero, t0, 0
	jr t0
	
	NEXT:
	
	# b) bgt t0, t1, LABEL
	li t0, 20
	li t1, 10
	blt t1, t0, NEXT1
	bgt t0, t1, NEXT1
	
	
	NEXT1:
	
	# c) ladd t0, t1, LABEL # to = t1 + label
	li t1, 4
	la t0, NEXT2
	add t0, t1, t0
	jr t0
	
	NEXT2:
	
	nop
	# d) sq t0, t1 # t0 = t1**2
	li t1, 5
	mul t0, t1, t1
	
	# exit
	li a7, 10
	ecall
