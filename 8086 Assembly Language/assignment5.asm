TITLE Assignment 5
; Date: 11/6/2019
Comment !
Write a program that:
1. Clears the screen, locates the cursor near the middle of the screen.
2. Prompts the user for two signed integers.
3. Displays their sum and difference.
4. Repeats the same steps three times. 
   Clears the screen after each loop iteration.
5. You might need to call the following 
   procedures from irvine32 library:
6. You need to create the following procedures:
   Locate. It needs to be called before anything 
   displays on the screen. Where it sets the cursor position.             
   Input: this procedure prompts the user and saves the input.
   DisplaySum: calculates and displays the sum.
   DisplayDiff: calculates and displays the difference. 
   (first input - the second input)
   WaitForKey; It needs to be called at the end of each iteration. 
   It displays "Press any key..." and waits for an input
!


INCLUDE Irvine32.inc

.data
	firstInteger SDWORD 0
	secondInteger SDWORD 0

	theSum SDWORD 0
	theDifference SDWORD 0

	printSum BYTE "The sum is: ", 0
	printDifference BYTE "The difference is: ", 0

	printGetInt BYTE "Enter an integer: ", 0
	printNextLoop BYTE "Press any key...", 0
	
.code
Main proc

			mov ecx, 3		; Loop 3 times
onlyLoop:	call clrscr		; Screen gets cleared
			mov bh,10		; Reset BH/DH register

	call Locate
	call Input
	call calculateSum

	call Locate
	call DisplaySum
	call calculateDifference

	call Locate
	call DisplayDiff

	call Locate
	call WaitForKey
Loop onlyLoop

	call Locate
	exit
main endp


;Description: Locate, Locate the cursor in the middle of the screen
;Receive: Y-coordinate (row) in DH, X-coordinate (column) in DL
;Return: None (Locate cursor) 
Locate PROC
	mov dh, bh	;row 10
	mov dl, 20	;column 20
	call Gotoxy
	inc bh
	ret
Locate endp


;Description: Input, Prompt user and save the input in 
;variables firstInteger and secondInteger
;Receive: firstInteger and secondInteger
;Return: None 
Input PROC
	mov edx, offset printGetInt
	call writeString
	call readInt
	mov firstInteger, eax
	call Locate
	mov edx, offset printGetInt
	call writeString
	call readInt
	mov secondInteger, eax
	ret
Input endp 


;Description: calculateSum, calculate the sum of 2 integers
;Receive: 2 integers stored in variables firstInteger and secondInteger
;Return: Sum of the firstInteger and secondInteger
calculateSum PROC
	mov esi, firstInteger
	Add esi, secondInteger
	mov theSum, esi
	ret
calculateSum endp


;Description: calculateDifference, calculate the difference 
;between firstInteger and secondInteger
;Receive: 2 integers stored in variables firstInteger and secondInteger
;Return: Difference of the firstInteger and secondInteger
calculateDifference PROC
	mov eax, 0
	mov eax, firstInteger
	SUB eax, secondInteger
	mov theDifference, eax
	ret
calculateDifference endp


;Description: DisplaySum, displays the sum of 
;firstInteger and secondInteger
;Receive: sum of firstInteger and secondInteger
;Return: Nothing (Display sum)
DisplaySum PROC
	mov edx, offset printSum
	call writeString
	mov eax, theSum
	call writeInt
	call crlf
	ret
DisplaySum endp


;Description: DisplayDiff, displays the difference 
;of firstInteger and secondInteger
;Receive: difference of firstInteger and secondInteger
;Return: Nothing (Display difference)
DisplayDiff PROC
	mov edx, offset printDifference
	call writeString
	mov eax, theDifference
	call writeInt
	call crlf
	ret
DisplayDiff endp


;Description: WaitForKey, displays "Press any key..." 
;and waits for an user input
;Receive: A character
;Return: Nothing (Displays "Press any key...").
WaitForKey PROC
	mov edx, offset printNextLoop
	call writeString
	call readChar
	ret
WaitForKey endp

end Main

Comment!
 Enter an integer: 40
 Enter an integer: 20
 The sum is: +60
 The difference is: +20
 Press any key...                                                                                                                                 

 Enter an integer: -20
 Enter an integer: 45
 The sum is: +25
 The difference is: -65
 Press any key...  

 Enter an integer: 33
 Enter an integer: -40
 The sum is: -7
 The difference is: +73
 Press any key...  
					
C:\Users\v\OneDrive\Desktop\Project32_VS2017\Debug\Project.exe 
(process 18128) exited with code 0.
To automatically close the console when debugging stops, 
enable Tools->Options->Debugging->Automatically close the 
console when debugging stops.
Press any key to close this window . . .                                        
!



