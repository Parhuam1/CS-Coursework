; Lab 1: working with the IDE
; Name: Parhuam Jalalian           

; 1. Put your name above. For the rest of the quarter, you should
;   always have your name at the top of your source file
; 2. In the first_text line below, replace the -- with your name


INCLUDE Irvine32.inc

.data
first_text BYTE "This is Parhuam Jalalian's first CIS21JA program", 0ah, 0dh, 0

.code
main PROC
	mov edx, OFFSET first_text
	call writeString	
    call crlf

	exit
main ENDP
END main