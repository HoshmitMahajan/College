section .data
msg1 db "Enter a string 1 (SIZE 5): ", 10H
msglen1 equ $-msg1
msg2 db "Enter a string 2 (SIZE 7): ", 10H
msglen2 equ $-msg2
msg3 db "NOT EQUAL", 20H
msg3len equ $-msg3
msg4 db "EQUAL", 20H
msg4len equ $-msg4

section .bss
string1 resb 15
string1len resq 1
string2 resb 15
string2len resq 1

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
	rw 1,1,msg1, msglen1
	rw 0,0,string1,15
	dec rax
	mov [string1len], rax
	
	rw 1,1,msg2, msglen2
	rw 0,0,string2,15
	dec rax
	mov [string2len], rax
	
	mov rax, [string1len]
	cmp rax, [string2len]
	jne down
	je down2
	down2:
		mov rsi, string1
		mov rdi, string2
		mov rcx, [string1len]
		loop:
			mov rax, 0
			mov rax, [rsi]
			cmp rax, [rdi]
			jne down
			inc rsi
			inc rdi
			dec rcx
			jnz loop
			rw 1,1,msg4, msg4len
			jmp concat
	down:
		rw 1,1,msg3, msg3len
		
	
	
	
	concat:
		mov rcx, 0
		mov rcx, [string2len]
		mov rdi, string1
		mov rsi, string2
		add rdi, [string1len]
		cld
		rep movsb
		
		mov rbx, [string1len]
		add rbx, [string2len]
		rw 1,1,string1, rbx
	
	rw 60,0,0,0
