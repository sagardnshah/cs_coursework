.text

.globl main
main:

	#displays message
	li $v0, 4
	la $a0, welmessage
	syscall

	#prints line and provides space
	li $v0, 4
	la $a0, space
	syscall
	
	li $v0, 4
	la $a0, prompt
	syscall
	
	
	li $v0, 5		#reads keyboard
	syscall
	move	$t0, $v0	#store n value into t0
	
	li $v0, 4 		#displays message to user
	la $a0, message
	syscall
	
	li $v0, 4 		#print new line and provide space
	la $a0, space
	syscall
	
	#Load the vars into registers
	lw $t1, i # t1 = i
	lw $t2, k # t2 = k
	lw $t3, p # t3 = p
	lw $t5, c # t4 = c
	lw $t6, d # t5 = d
	
	blt $t0, $t1 L2
	
	li $v0, 1	#prints interger function call 1
	move $a0, $t1	#interget to print out
	syscall
	
	
	li $v0, 4	#print new line and provide space
	la $a0, space
	syscall
	
#The Outer loop
L2: move $t3, $zero

	# The inner loop
L1: remu $t4, $t1, $t2
	bne $t4, $zero, I
	move $t3, $t5
	
I: add $t2, $t2, $t5		#increment k value
	blt $t2, $t1 L1
	bne $t3, $zero, P
	
		li $v0, 1	#print integer function call 1
		move $a0, $t1	# integer to print out
		syscall
		
	li $v0, 4		#print new line and provide space
	la $a0, space
	syscall
	
P: add $t1, $t1, $t5		#increment i value
	move $t2, $t6
	
	bgt $t1, $t0, E
	j L2
	
E: 	li $v0, 10 		#system all code for exit = 10
	syscall 		#call operating sys
	
end:	jr $ra
.data

#Prompts the user for inputs
space: .asciiz  "\n"
welmessage: .asciiz "Welcome to the Prime number finder program! "
prompt: .asciiz "Enter a # to find the prime value of:	"
message: .asciiz "The Prime #'s are:	"

i: .word 2
p: .word 0
k: .word 2
c: .word 1
d: .word 2
		
