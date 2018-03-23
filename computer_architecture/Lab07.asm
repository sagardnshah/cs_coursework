#Sagar Shah

.text
.globl main

main:
	li $v0, 4 	# Message for A
	la $a0, prompt1
	syscall

	li $v0, 5 	# keyboard input for A
	syscall

	move $t0, $v0	# keyboard input transfer to $t0

	li $v0, 4	# Message for B
	la $a0, prompt2
	syscall

	li $v0, 5 	# keyboard input for B
	syscall

	move $t1, $v0	# keyboard input transfer to $t0
	
	li $t2, 0	# initialize C to 0
	li $t6, 31	# n = 31
	li $t7, 0	# i =0

	While:
		bge $t7, $t6, Print	# jump to Print after running while n times
		andi $t3, $t1, 1 	# get LSB of B
		li $t4, 1 		# put 1 in $t4
		bne $t3, $t4, Else	# if LSB of B != 1, go to Else 
		addu $t2, $t2, $t0	# A+C

		Else:
		andi $t5, $t2, 1 		# get LSB of C
		srl $t2, $t2, 1 		#shift C right 1
		srl $t1, $t1, 1 		# shift B right 1
		bne $t5, $t4, cont 		# if LSB of C != 1, go to cont 
		ori $t1, $t1, 1073741824 	# set MSB to 1 is LSB of C was 1

		cont:
		addi $t7, $t7, 1	# i++		
		j While			# jump back to while

	Print:
	# display C
	li $v0, 1 
	move $a0, $t2
	syscall

	# display space
	li $v0, 4
	la $a0, space
	syscall

	# display B
	li $v0, 1 
	move $a0, $t1
	syscall

	# exit
	end: li $v0, 10 
	syscall 

.data
prompt1: .asciiz "Give me A:"
prompt2: .asciiz "Give me B:"
space: .asciiz " "