section .data
str1 db "MIT"
str1len equ $-str1
str2 db "WPU"
str2len equ $-str2



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
	mov cl, str2len
	mov rdi, str1
	mov rsi, str2
	add rdi, str1len
	up:
		mov al, [rsi]
		mov [rdi], al
		inc rsi
		inc rdi
		dec rcx
		jnz up   
	
	
	rw 1,1,str1, 6
		
rw 60,0,0,0                                                                                                                                                         
