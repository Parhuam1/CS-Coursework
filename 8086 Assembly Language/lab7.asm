TITLE Lab 7: Procedures

; Learning fundamentals of Procedures
; Parhuam Jalalian
; 3/5/2019

COMMENT !
Modify the code of lab 5 so that the program is made of procedures. 
The code should still do the same work as lab 5: add 2 unsigned, 
16-bit integers and print the sum as a numeric text string.
!

INCLUDE Irvine32.inc

mWriteStr MACRO userInput
	push edx
	mov edx, userInput
	call writeString
	pop edx
ENDM

.data
num1			WORD ?
num2			WORD ?
sum				WORD ?
theString 		BYTE 5 DUP(?), 0

uFirstOutput	BYTE "Enter first 16 bit unsigned integer: ", 0
uSecondOutput	BYTE "Enter second 16 bit unsigned integer: ", 0
uSum 		    BYTE "Sum = ", 0
uContinue 		BYTE "Continue? y/n: ", 0

uError   		BYTE "The number must be between 0 and 65,535", 0
uError2  		BYTE "The sum is too large", 0


.code
main PROC
mov eax, 0

Beginning:
	sub esp, 4						; Save room for return value
	push OFFSET uFirstOutput		; Push first user output
	push OFFSET uError				; Push first error string
	call readInput					; Procedure
	pop eax							; First user input enters eax
	mov num1, ax					
	sub esp, 4

	push OFFSET uSecondOutput		; For second input
	push OFFSET uError 
	call readInput					
	pop eax							
	mov num2, ax					
	sub esp, 4	
	
	movzx eax, num1					; Save num1 to eax			
	push eax						
	movzx eax, num2					; Save num2 to eax		
	push eax
	push OFFSET sum					; Save sum into stack
	call adding						; Procedure
	pop eax							
	cmp eax, 1						; If 1, continue
	ja flagError
	movzx eax, sum

	mov edx, OFFSET uSum			; Pass sum by address
	mov ebx, OFFSET theString		; Pass sum by address
	call PrintOutput

Restart:								
	mWriteStr OFFSET uContinue 			;Print if user wants to coninue program
	call crlf
	call readChar

	cmp al, 'Y'							;Check for upper or lowercase response
	je Beginning
	cmp al, 'y'
	je Beginning
	jmp Finish

flagError:
	mWriteStr OFFSET uError2  
	jmp Restart

Finish:

exit	
main ENDP


readInput PROC
	push ebp					; Save all to stack
	mov ebp, esp

	push edx
	push ecx

Input:
	mWriteStr [ebp + 12]		; Write out strings
 	call readInt

	cmp eax, 0
	jl Error

    cmp eax, 0FFFFh  
	ja Error

	movzx ecx, ax				
	mov [ebp + 16], ecx


Ending:
	pop ecx						; Pop everything
	pop edx
	pop ebp
	ret 8						; return and clean up 2 input args

Error:
	mWriteStr [ebp + 4]
	jmp Input

readInput ENDP

adding PROC
	push ebp						; Save
	mov ebp, esp					; Move to stack
	pushad							; save all registers
	mov bx, [ebp + 12] 
	mov ax, [ebp + 16]
	mov ecx, [ebp + 8]
	add bx, ax 
	jc Big
	mov DWORD PTR[ebp + 20], 1

	mov [ecx], bx 
	popad							; pop all out
	pop ebp					
	ret 12							; return and clean up 3 input args

Big:
	mov DWORD PTR[ebp + 20], 0		; Check if 1
	popad							
	pop ebp
	ret 12							; return and clean up 3 input args
adding ENDP

printOutput PROC
	pushad							; save all registers
	mov di, 10								
	mov ecx, 5								
	dec ebx
	
CreateString:
	mov dx, 0						; Clear dx register
	div di								
	add dl, 48d							
	add ebx, ecx
	mov BYTE PTR[ebx], dl		
	sub ebx, ecx
	loop CreateString	
	
	popad							; pop all out
	mWriteStr edx					; Print
	mWriteStr ebx					; Print
	call crlf
	ret								; return
printOutput ENDP

END main
