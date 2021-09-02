TITLE Assignment 6
; Date: 11/9/2019
Comment !
A prime number is an integer that is divisible only by 1 and by itself. 
Write a program that:
1.      Takes a number as an input.
2.      Prints back to the console all the primes that are larger than 
1 but not larger than the number that has been entered.

You need to have a procedure called isPrime. 
You may have more procedures if you like.

1.  This procedure receives a number through one of the registers.
2.  Checks if this number is prime.
3.  Returns back through one of the registers to the main program 1, 
		if the number is prime, 0 otherwise.
!

incLUDE Irvine32.inc

.data
	spacebar BYTE " ", 0
	userInput DWORD 0		;Store input

	integerPrint BYTE "Please enter a number: ", 0 
	primePrint BYTE	"Primes found until the given number: ",0


.code

;Description: Main, ties procedures togethor
;Recieve: None
;Return: None
Main PROC
	call getInput
	call printDisplay
	mov esi, 2

; Print prime numbers
	secondWhile: 
	cmp esi, userInput
	jg endsecondWhile

	call IsPrime
	cmp ecx, 1
	jne endTwo
	mov eax, esi

	; Print if prime number	
	call writeDec				
	mov edx, offset spacebar
	call writeString

    endTwo: 
	inc esi
	jmp secondWhile

	endsecondWhile: 
	call crlf
	exit
Main endp	


;Description: getInput, this procedure asks for user input
;and saves in variable userInput
;Recieve: An integer from user
;Return: None
getInput PROC
	mov edx, offset integerPrint
	call writeString
	call readDec
	mov userInput, eax
	call crlf
	ret
getInput endp


;Description: printDisplay, this procedure prints Output
;Recieve: None
;Return: None
printDisplay PROC
mov edx, offset primePrint
	call writeString
	call crlf
	call crlf
	ret
printDisplay endp


;Description: IsPrime, this procedure checks if this number is prime
;Recieve: A number through one of the registers (ecx)
;Return: Returns back to the main program 1, if the 
;number is prime, 0 otherwise
IsPrime PROC
	mov ecx, 1
	mov ebx, 2

	; check if prime
firstWhile:		
	cmp ebx, esi
	jge endfirstWhile
	xor edx, edx		
	mov eax, esi

	; check if there is a remainder
	div ebx	
	
	; if remainder, not prime
	test edx, edx			
	jne endOne
	xor ecx, ecx			
	jmp endfirstWhile

endOne:
	inc ebx
	jmp firstWhile

endfirstWhile:
	ret
IsPrime endp	

end Main	


Comment!
Please enter a number: 44

Primes found until the given number:

2 3 5 7 11 13 17 19 23 29 31 37 41 43

C:\Users\\OneDrive\Desktop\\Project32_VS2017\Debug\Project.exe 
(process 13544) exited with code 0.
To automatically close the console when debugging stops, 
enable Tools->Options->Debugging->Automatically close the 
console when debugging stops.
Press any key to close this window . . .
!