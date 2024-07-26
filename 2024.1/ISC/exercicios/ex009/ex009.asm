# lista
.data
	alemanha: .string "exercicios/ex009/alemanha.bin"
	russia: .string "exercicios/ex009/russia.bin"
	franca: .string "exercicios/ex009/franca.bin"
	dinamarca: .string "exercicios/ex009/dinamarca.bin"
	inglaterra: .string "exercicios/ex009/inglaterra.bin"
	japao: .string "exercicios/ex009/japao.bin"
	nigeria: .string "exercicios/ex009/nigeria.bin"
	suica: .string "exercicios/ex009/suica.bin"
	suecia: .string "exercicios/ex009/suecia.bin"
	belgica: .string "exercicios/ex009/belgica.bin"
	polonia: .string "exercicios/ex009/polonia.bin"
	brasil: .string "exercicios/ex009/brasil.bin"
	
.text

	loop:
		read:
			li t0, 0xFF200000
			lw t1, (t0)
			andi t1, t1, 1
			beqz t1, read
		lw s1, 4(t0)
		
		# checa qual letra foi pressionada
		li t2, 'A'
		beq s1, t2, a
		li t2 'a'
		beq s1, t2, a
		
		li t2, 'R'
		beq s1, t2, r
		li t2, 'r'
		beq s1, t2, r
		
		li t2, 'F'
		beq s1, t2, f
		li t2, 'f'
		beq s1, t2, f
		
		li t2, 'D'
		beq s1, t2, d
		li t2, 'd'
		beq s1, t2, d
		
		li t2, 'I'
		beq s1, t2, i
		li t2, 'i'
		beq s1, t2, i
		
		li t2, 'J'
		beq s1, t2, ja
		li t2, 'j'
		beq s1, t2, ja
		
		li t2, 'N'
		beq s1, t2, n
		li t2, 'n'
		beq s1, t2, n
		
		li t2, 'S'
		beq s1, t2, s
		li t2, 's'
		beq s1, t2, s
		
		li t2, 'E'
		beq s1, t2, sue
		li t2, 'e'
		beq s1, t2, sue
		
		li t2, 'B'
		beq s1, t2, be
		li t2, 'b'
		beq s1, t2, be
		
		li t2, 'P'
		beq s1, t2, p
		li t2, 'p'
		beq s1, t2, p
		
		li t2, 'Z'
		beq s1, t2, br
		li t2, 'z'
		beq s1, t2, br
		
		# q quits
		li t2, 'q'
		beq s1, t2, exit
		
		j loop
		
		a: 
			la a0, alemanha
			j render
		r:
			la a0, russia
			j render
		f:
			la a0, franca
			j render
		d:
			la a0, dinamarca
			j render
		i:
			la a0, inglaterra
			j render
		ja:
			la a0, japao
			j render
		n:
			la a0, nigeria
			j render
		s:
			la a0, suica
			j render
		sue:
			la a0, suecia
			j render
		be:
			la a0, belgica
			j render
		p:
			la a0, polonia
			j render
		br:
			la a0, brasil
			j render
		
		
		render:
		# abre o arquivo bin
		li a7, 1024
		li a1, 0
		li a2, 0
		ecall
		mv s2, a0
		
		# le o arquivo para a memoria do bitmap
		# imprime na tela
		li a7, 63
		li a1, 0xFF000000
		li a2, 76800
		ecall
		
		# fecha o arquivo
		li a7, 57
		mv a0, s2
		ecall
		
		j loop
		
	exit:
	li a7, 10
	ecall
	
