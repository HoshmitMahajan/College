section .data
msg1 db "Enter the first number: ", 10
msglen1 equ $-msg1
msg2 db "Enter the second number: ", 10
msglen2 equ $-msg2

section .bss
A resb 1
B resb 1
result resb 8
temp resb 8

%macro rw 4
	mov rax, %1
	mov rdi, %2
	mov rsi, %3
	mov rdx, %4
	syscall
%endmacro


section .text

global _start

_start: rw 1,1,msg1,msglen1
	rw 0,0,A,1
	sub A, #30H


	rw 1,1,msg2, msglen2
	rw 0,0,B,1
	sub B, #30H
	
	
	mov ah, byte[A]
	mov ch, byte[B]
	add ah, ch
	
	mov bp, 2
	up: rol ax, 4
	    mov bx,ax
	    and ax, 0FH
	    cmp al, 09
	    jbe down
	        add al, 07H
	    down: add al, 30H
	    	  mov byte[temp], al
	    	  rw 1,1,temp,1
	    	  mov ax,bx
	    	  dec bp
	    	  jnz up
	    	  
	    	  
	mov rax, 60
	mov rdi, 0
	syscall
	
	
	
