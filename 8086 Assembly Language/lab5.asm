TITLE Lab 5: LOOP

; Learning fundamentals of LOOPS
; Parhuam Jalalian
; 2/12/2019

COMMENT !
Write a program that adds 2 unsigned, 16-bit integers and prints the sum as a numeric text string.
!

INCLUDE Irvine32.inc

.data
theString BYTE 5 DUP(?), 0
uFirstOutput BYTE "Enter first 16 bit unsigned integer: ", 0
uSecondOutput BYTE "Enter second 16 bit unsigned integer: ", 0
uError BYTE "The number must be between 0 and 65,535", 0
uError2 BYTE "The number is larger than 16 bits", 0
uSum BYTE "Sum = ", 0
uContinue BYTE "Continue? y/n: ", 0


.code
main PROC

First_1:
	mov edx, OFFSET uFirstOutput       ;print prompt
	call WriteString
	call readInt					   ;get user input

	cmp eax, 0						   ;Check if below 0, to check if negative
	jl Error_1						   ;Jump if true

	cmp eax, 0FFFFh					   ;Check if above 65,535, to check if its bigger
	ja Error_1						   ;Jump if true

	mov bx, ax

Second_2:
	mov edx, OFFSET uSecondOutput	   ;print prompt, store second user input in cx
	call WriteString
	call readInt					   ;get user input

	cmp eax, 0						   ;Check if below 0, to check if negative
	jl Error_2						   ;Jump if true

	cmp eax, 0FFFFh					   ;Check if above 65,535, to check if its bigger
	ja Error_2						   ;Jump if true
	mov cx, ax

add cx, bx                             ;Add sum
jc Error_3							   ; Print if not valid
jc Restart
	

mov di, 10	 ;start conversion process                        
mov ax, cx	 ; integer to ASCII
mov ecx, 5

giveAnswer:		; Loop 5 times
    mov dx, 0	; clears dx
    div di
    add dl, 48d
    mov theString[ecx-1], dl		; moves converted int to ASCII into array
	cmp ax, 0
    loop giveAnswer

	mov edx, OFFSET uSum				; Print out sum string
	call writeString

	mov edx, OFFSET theString			; Print out final sum
	call writeString
	call crlf

Restart:
    mov edx, OFFSET uContinue ; Ask user if they want to exit
    call writeString
	call crlf
    call readChar

    cmp al, 59h				  ; Check if user response is 'Y' or 'y'
    je First_1
    cmp al, 79h
    je First_1
	
	jmp EndProgram


Error_1:							   ;If first input is wrong, trigger error, jump back
    mov edx, OFFSET uError
    call writeString
	call crlf						   ;new line
    jmp First_1

Error_2:							   ;If second input is wrongg, trigger erorr, jump back
    mov edx, OFFSET uError
    call writeString
	call crlf						   ;new line
    jmp Second_2

Error_3:
	mov edx, OFFSET uError
    call writeString
	call crlf						   ;new line
    jmp Restart


EndProgram:

	exit	
main ENDP

END main



