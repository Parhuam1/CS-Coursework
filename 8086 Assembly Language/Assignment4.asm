TITLE Assignment 4
; Date: 10/30/2019
Comment !
Write a complete program that:
    1. Prompt the user to enter 10 numbers.
    2. save those numbers in a 32-bit integer array.
    3. Print the theArraywith the same order it was entered.
    3. Calculate the sum of the numbers and display it.
    4. Calculate the mean of the theArrayand display it.
    5. Rotate the members in the theArrayforward one position for 
       9 times. so the last rotation will display the 
	   theArrayin reversed order.
    6. Print the theArrayafter each rotation.
       check the sample run.
!

INCLUDE Irvine32.inc

.data
theSum DWORD 0
theMean DWORD 0
theArray DWORD 10 DUP(?)
testArray DWORD 9 DUP(?)
incrementArray BYTE 0
numberZero DWORD 0

spacebar BYTE " ", 0
firstPrint BYTE "Please enter a number:", 0

sumFinal BYTE "The sum is:", 0
meanFinal BYTE "The mean is:", 0
extraString BYTE "/10", 0
firstArray BYTE "The original array:", 0
testString BYTE "12345678", 0	;9

theRotation BYTE "After a rotation:", 0
firstHold DWORD 0		; keep track of ecx 
secondHold DWORD 0		; keep track of ebx 


.code
main proc

mov ecx, lengthof theArray
mov edi, numberZero

;Prompt the user to enter 10 numbers.
firstloop:								
mov edx, offset firstPrint
call writeString
call readdec

;Save those numbers in a 32-bit integer array.
mov theArray[edi], eax			
add edi, type theSum	;4

;Calculate the sum of the numbers 
add theSum, eax				
loop firstloop
mov eax, theSum

;Display sum
mov edx, offset sumFinal	
call writeString
call writeDec
call crlf

;Calculate the mean of the array 
mov edx, numberZero					
mov ecx, lengthof theArray	;10
div ecx
mov ebx, edx

;Displays mean
mov edx, offset meanFinal	
call writeString
call writeDec
mov eax, ebx
mov edx, offset spacebar
call writeString
call writeDec

;Display the decimal of the mean
mov edx, offset extraString		
call writeString
call crlf
mov edx, offset firstArray
call writeString
mov ecx, lengthof theArray	;10
mov ebx, numberZero


secondLoop:
mov eax, [theArray+ ebx]
call writeDec				

;Print the original array
mov edx, offset spacebar
call writeString
add ebx, type theSum	;4
loop secondLoop
call crlf

;Rotate array
mov ecx, sizeof testString	;9			

;Change index of array
mov ebx, numberZero	

;Keep track of forth loop
mov edi, lengthof theArray				

;Rotate the array one position 9 times
thirdLoop:	
mov firstHold, ecx		
mov ecx, edi	
mov esi, [theArray+ sizeof testArray] ;36
mov secondHold, ebx

fourthLoop:	

;Exchange the values of counter and array
xchg esi, [theArray+ ebx]		
add ebx, type theSum ;4

;End loop 4
loop fourthLoop						

mov edx, offset theRotation	
call writeString
mov ecx, lengthof theArray
mov ebx, numberZero

fifthLoop:	
mov eax, [theArray+ ebx]

;Prints array after rotation
call writeDec				
mov edx, offset spacebar
call writeString
add ebx, type theSum	;4
loop fifthLoop
call crlf

mov ebx, secondHold
add ebx, type theSum	;4					
sub edi, type spacebar  ;1
mov ecx, firstHold
loop thirdLoop						


	exit	
main ENDP

END main


Comment !
Please enter a number:2
Please enter a number:3
Please enter a number:4
Please enter a number:5
Please enter a number:6
Please enter a number:7
Please enter a number:8
Please enter a number:9
Please enter a number:0
Please enter a number:10
The sum is:54
The mean is:5 4/10
The original array:2 3 4 5 6 7 8 9 0 10
After a rotation:10 2 3 4 5 6 7 8 9 0
After a rotation:10 0 2 3 4 5 6 7 8 9
After a rotation:10 0 9 2 3 4 5 6 7 8
After a rotation:10 0 9 8 2 3 4 5 6 7
After a rotation:10 0 9 8 7 2 3 4 5 6
After a rotation:10 0 9 8 7 6 2 3 4 5
After a rotation:10 0 9 8 7 6 5 2 3 4
After a rotation:10 0 9 8 7 6 5 4 2 3
After a rotation:10 0 9 8 7 6 5 4 3 2

C:\Users\z\OneDrive\Desktop\Project32_VS2017\Debug\Project.exe 
(process 26484) exited with code 0.
To automatically close the console when debugging stops, 
enable Tools->Options->Debugging->Automatically 
close the console when debugging stops.
Press any key to close this window . . .
!



