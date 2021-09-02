TITLE  Assignment 6: Use bit wise instructions
		
; Name: Parhuam Jalalian
; Date: 2/21/2019

INCLUDE Irvine32.inc

.data
zeroStr BYTE "EAX is 0", 0ah, 0dh, 0
divStr BYTE "Divisible by 4", 0ah, 0dh, 0
arr WORD 1, -2, -3, 4


.code
main PROC

;-----------------------------------------------------------------
; Question 1 (3pts)
; In the space below, without using CMP and without modifying EAX,
; write code in 3 different ways (use 3 different instructions)
; to check whether EAX is 0 and jump to label Zero if it is, 
; otherwise jump to Q2.

	mov eax, 0		; change this value to test your code

	; First way
	mov ebx, eax
	and eax, 0ffffffffh
	jz Zero

	; Second Way
	or eax, eax
	jz Zero
	
	; Third way
	test eax, 0ffffffffh
	jz   Zero

	jmp Q2

	Zero :
		mov edx, OFFSET zeroStr
		call writeString
		call crlf

	Q2:
;-----------------------------------------------------------------


; Question 2
; You can use the following code to impress your friends, 
; but first you need to figure out how it works.

	mov al, 'A'	    ; al can contain any letter of the alphabet
	xor al, ' '	    ; the second operand is a space character

COMMENT !
a. (1pt) What does the code do to the letter in AL?  
   (Print the letter in AL to see)
	Makes upercase A-Z to lowercase a-z

b. (2pts) Explain how it works.
A-Z's 6th bit is always 0, by using XOR with space and the capital letters,
we flip the capitals letter 6th bit which is 0 to 1, basically adding 32
which makes it lowercase
!
;-----------------------------------------------------------------

; Question 3 (4 pts)
; Write code to check whether the data in AL is divisible by 4,
; jump to label DivBy4 if it is, or go to label Q4 if it's not.
; You should not have to use the DIV or IDIV instruction.

    mov al, 8     ; change this value to test your code


	test	al, 000000003d			; 0000 0011, Everything past these 2 bits are divisible by 4
	jz		DivBy4
	jmp		Q4


	DivBy4:
		mov edx, OFFSET divStr
		call writeString
		call crlf

	Q4:
;-----------------------------------------------------------------
	
; Question 4 (5 pts)
; Given an array arr as already defined in .data above, 
; and ebx is initialized as shown below.
; Using ebx (not the array name), write ONE instruction 
; to reverse the MSB of the last 2 elements of arr.  
; Reverse means turn 0 to 1 or 1 to 0.  
; Your code should work with all values in arr, 
; not just the sample values above.

	mov ebx, OFFSET arr					;IMPORTANT: I coudn't figure it out how to do it in ONE instruction with the slides
	XOR WORD PTR [ebx+4], 8000h			; I will probably wait for you to show your version in class so I can learn
	XOR WORD PTR [ebx+6], 8000h			; since I have a Calc Midterm coming 2/22 and I spent most of my time studying
										; Looking foward to see the solution

	exit	
main ENDP

END main
