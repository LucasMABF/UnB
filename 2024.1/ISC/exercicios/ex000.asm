.data
	HELLO: .string "Hello, World!"
	
.text
	# print string
	la a0, HELLO
	li a7, 4
	ecall
	
	# exit
	li a7, 10
	ecall
