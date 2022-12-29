.text
li $a0, 15
li $a1, 20
li $a2, 10
li $a3, 5

exemplo:
addi $sp, $sp, -12
sw $t1, 8 ($sp)
sw $t0, 4 ($sp)
sw $s0, 0 ($sp)

add $t0, $a0, $a1
add $t1, $a2, $a3
sub $s0, $t0, $t1
add $v0, $s0, $zero

lw $s0, 0 ($sp)
lw $t0, 4 ($sp)
lw $t1, 8 ($sp)
addi $sp, $sp, 12

jr $ra