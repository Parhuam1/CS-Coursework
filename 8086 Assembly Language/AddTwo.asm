; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
num1 WORD 0;
num2 WORD 0;



.code
main proc

mov ax, 4;
mov num2, ax;
mov ax, num1;



	invoke ExitProcess,0
main endp
end main