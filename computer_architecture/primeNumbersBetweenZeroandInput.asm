# this program prints out the maximum of two numbers 
# The two numbers are read through the keyboard 
.text
.globl main

#t0 = n
#$t1 = outer loop counter (i)
#$t2 = inner loop counter (j)
#t3 = p
#t4 = remainder


main:
# Display prompt1
li $v0, 4
la $a0, prompt1
syscall

li $v0, 5 # read keyboard into $v0 (number x is number to test)
syscall

move $t0,$v0 # move the first number from $v0 in $t0


addi $t1, $zero, 2 #i
while0: bge  $t1, $t0, skipWhile0 # end loop if i >= y

addi $t3, $t3, 0 #p

addi $t2, $zero, 2 #j
while1: bge $t2, $t1, skipWhile1 #end loop if j >= i
remu $t4, $t1, $t2 #computer mod
#if $t4 == 0, then p=1
beq $t4, $zero, setP
j skipP #leave p alone
setP: addi $t3, $zero, 1 #set p to 1
skipP:
#end if
addi $t2, $t2, 1 #j++
j while1
#if p=0, then print
beq $t3, $zero, printPrime
j skipPrint
printPrime:

li $v0, 1
move $a0, $t1
syscall

skipPrint:
addi $t1, $t1, 1 #i++
j while0
skipWhile1:
skipWhile0:


#exit
end: li $v0, 10 
syscall 
 
.data
prompt1:
 .asciiz "Enter the number "