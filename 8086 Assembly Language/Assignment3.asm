TITLE Assignment 3: Write a complete program that will input values and display the value of the expression
; Date: 10/16/2019
; User will input num1 ,num2, and num3, and the program will display the value of the expression ( (num1 ^ 3) * num2 + 5 * ( num2 ^ 2) ) / num3.
		
INCLUDE Irvine32.inc

.data
num1 BYTE " num1 = ", 0   ; Prompts
num2 BYTE " num2 = ", 0   
num3 BYTE " num3 = ", 0	  

sumOutput BYTE " ((num1 ^ 3) * num2 + 5 * ( num2 ^ 2)) / num3 = ", 0    ;Output
remainderOutput BYTE " R "  

.code
main PROC

mov edx, OFFSET num1    ;print prompt, store num1 in edi
call WriteString
call readDec
mov edi, eax	

mov edx, OFFSET num2	;print prompt, store num2 in ebx
call WriteString
call readDec
mov ebx, eax

mov edx, OFFSET num3    ;print prompt, store num3 in ecx
call WriteString
call readDec
mov ecx, eax

; 32 bit registers are used since user input cannot exceed past 32-bits
; Calculations
mov eax, edi ; eax = num1
mul edi		 ; num1*num1
mul edi		 ; num1*num1
mov edi, eax ; edi = num1^3 (num1*num1*num1)
mov eax, ebx ; eax = num2
mul ebx      ; eax = num2*num2
mov esi, 5	 ; esi = 5
mul esi		 ; eax = 5 * ( num2 ^ 2)
mov esi, eax ; esi = 5 * ( num2 ^ 2)
mov eax, edi ; eax = num1^3 (num1*num1*num1)
mul ebx		 ; eax = (num1 ^ 3) * num2
add eax, esi ; eax = (num1 ^ 3) * num2 + 5 * ( num2 ^ 2)
div ecx		 ; eax = ((num1 ^ 3) * num2 + 5 * ( num2 ^ 2)) / num3,  final result
mov ebp, eax ; Save eax into another register, because eax is about to be overwritten by writeDec etc
mov ecx, edx ; Save edx into another register, because edx holds the remainder and will be overwritten

;Result
mov edx, OFFSET sumOutput ;print final result
call WriteString
mov eax, ebp
call writeDec

mov edx, OFFSET remainderOutput ;print remainder next to result
call WriteString
mov eax, ecx
call writeDec

	exit	
main ENDP

END main

; num1 =  1
; num2 =  2
; num3 =  3
; ((num1 ^ 3) * num2 + 5 * ( num2 ^ 2)) / num3 = 7 R 1
; C:\Users\parhu\OneDrive\Desktop\Project32_VS2017 old\Project32_VS2017\Debug\Project.exe (process 18188) exited with code 0.
; To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
; Press any key to close this window . . .

