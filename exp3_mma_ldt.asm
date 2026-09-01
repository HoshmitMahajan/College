section .data

msg2 db 10, "THE SEGMENT ADDR IS: ", 10
msglen2 equ $-msg2

section .bss

value resb 4
temp resb 1

%macro rw 4
	mov rax, %1
	mov rdi, %2
	mov rsi, %3
	mov rdx, %4
	syscall
%endmacro


section .text

global _start

_start:
	sldt [value]
		    	  
	rw 1,1,msg2, msglen2 	
	mov ax, word[value]

	mov bp, 4
		up2: rol rax, 4
		    mov rbx,rax
		    and rax, 0FH
		    cmp al, 09
		    jbe down2
			add al, 07H
		    down2: add al, 30H
		    	  mov byte[temp], al
		    	  rw 1,1,temp,1
		    	  mov rax,rbx
		    	  dec bp
		    	  jnz up2
	  
		    	  
	mov rax, 60
	mov rdi, 0
	syscall
