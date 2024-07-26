# laboratorio
# 1049 - Animal
.data
	VERTEBRA: .space 32
	CLASSE: .space 32
	DIETA: .space 32
	AGUIA: .string "aguia"
	POMBA: .string "pomba"
	HOMEM: .string "homem"
	VACA: .string "vaca"
	PULGA: .string "pulga"
	LAGARTA: .string "lagarta"
	SANGUESSUGA: .string "sanguessuga"
	MINHOCA: .string "minhoca"
	
	
.text
	# get string input
	li a7, 8
	la a0, VERTEBRA
	li a1, 32
	ecall
	
	la a0, CLASSE
	ecall
	
	la a0, DIETA
	ecall
	
	# already sets to print the string
	li a7, 4
	
	# testa letras para achar animal correspondente
	la t0, VERTEBRA
	lb t1, (t0)
	li t2, 'v'
	bne t1, t2, INVERTEBRADO
	VERTEBRADO:
		la t0, CLASSE
		lb t1, (t0)
		li t2, 'a'
		bne t1, t2, MAMIFERO
		
		AVE:
			la t0, DIETA
			lb t1, (t0)
			li t2, 'c'
			bne t1, t2, ONIVORO
			
			CARNIVORO:
				la a0, AGUIA
				j END
			ONIVORO:
				la a0, POMBA
				j END		
		
		MAMIFERO:
			la t0, DIETA
			lb t1, (t0)
			li t2, 'o'
			bne t1, t2, HERBIVORO
			
			ONIVORO1:
				la a0, HOMEM
				j END
			HERBIVORO:
				la a0, VACA
				j END
	
	INVERTEBRADO:
		la t0, CLASSE
		lb t1, (t0)
		li t2, 'i'
		bne t1, t2, ANELIDEO
		
		INSETO:
			la t0, DIETA
			lb t1, 2(t0) # first and seccond letters equal
			li t2, 'm'
			bne t1, t2, HERBIVORO1
			
			HEMATOFAGO:
				la a0, PULGA
				j END
			HERBIVORO1:
				la a0, LAGARTA
				j END
				
		ANELIDEO:
		
			la t0, DIETA
			lb t1, (t0)
			li t2, 'h'
			bne t1, t2, ONIVORO2
			
			HEMATOFAGO1:
				la a0, SANGUESSUGA
				J END
			ONIVORO2:
				la a0, MINHOCA
				j END
	
	
	END:
	# print the string
	ecall
	li a7, 11
	li a0, '\n'
	ecall
	
	li a7, 10
	ecall
		
	
	
