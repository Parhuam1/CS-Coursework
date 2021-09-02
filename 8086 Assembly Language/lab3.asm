TITLE Lab 3: assembly language fundamentals				

;;;;; Q1: Don't forget to document your program 			
; Name: Parhuam Jalalian

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;; Answer each question below by writing code at the APPROPRIATE places in the file.
;;;;; Hint: the appropriate place is not always right below the question.

;;;;; Q2: Write the directive to bring in the IO library			

;;;;; Q3: Create a constant called MAX and initialize it to 150

;;;;; Q4: Create a constant called MIN and intialize it to 15% of MAX (from Q3) 
;;;;;     in an integer expression constant

;;;;; Q5: Define an array of 20 signed doublewords, use any array name you like. 
;;;;; Initialize:
;;;;;	- the 1st element to -250 
;;;;;	- the 2nd element to the hexadecimal value A924
;;;;;	- the 3rd element to the binary value 10100 
;;;;;	- the 4th element to MAX (from Q3). Use MAX, not a number.
;;;;; and leave the rest of the array uninitialized.  

;;;;; Q6. Define the string "Output = ", use any variable name you like.
;out DB "Output=",0

;;;;; Q7. Define a prompt that asks the user for a number.
;uPrompt BYTE  "Enter your Number: " ,0

;;;;; Q8. Write code to store the value of MIN into eax, then print the value
;;;;;     to screen. 
;;;;;     Use the string you defined in Q6 as the text explanation for your output.

;;;;; Q9. Write code to prompt the user for a number, using the prompt string that 
;;;;;     you defined in Q7.

;;;;; Q10. Write code to read in the user input, which you can assume is always
;;;;;      a positive number. Hint: use the correct library routine for positive number.

;;;;; Q11. Write code to print "Output = " and then echo to screen the user input.

;;;;; Q12. Write code to print "Output = " and then print the first element of the 
;;;;;      array defined in Q5.

;;;;; Q13. Build, run, and debug your code.

;;;;; Your output should be similar to this (without the commented explanation):
;;;;; Output is 22								; printing MIN
;;;;; Enter a positive number: 7                ; prompt the user for a number
;;;;; Output is 7								; echo user input
;;;;; Output is -250							; print first element of array
;;;;; Press any key to continue . . .

;;;;; Q14. At the end of the source file, without using semicolons (;), add a comment block
;;;;;      to show how bigData appears in memory (should be the same 8 hexadecimal values 
;;;;;      that you saw in assignment 2), 
;;;;;      and explain why it looks different than the actual value. 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
TITLE Lab 3: assembly language fundamentals	

; Learning fundamentals of assembly language
; Parhuam Jalalian
; 1/22/2019

INCLUDE Irvine32.inc

MAX = 150
MIN = (MAX * 15)/100

.data
bigData QWORD 0abcdef0123456789h		; same bigData value as last lab
myArray SDWORD -250, 0A924h, 10100b, MAX, 16 DUP(?)
uOutput BYTE "Output = ", 0
uPrompt BYTE "Enter a positive number: ", 0

.code
main PROC

mov edx, OFFSET uOutput
call WriteString
mov eax, MIN
call WriteDec
call Crlf

mov edx, OFFSET uPrompt
call WriteString
call ReadDec

mov edx, OFFSET uOutput
call WriteString
call WriteDec
call Crlf

mov edx, OFFSET uOutput
call WriteString
mov eax, myArray[0]
call WriteInt
call Crlf

	exit	
main ENDP

END main

COMMENT !
Big data in memory are the following 8 bytes:
89 67 45 23 01 ef cd ab 
Because little endian ordering of 8 byte value puts the least
significant bytes first in memory and the most significant bytes last
in memory
!