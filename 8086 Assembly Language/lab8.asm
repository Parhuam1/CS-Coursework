TITLE Lab 8: Array

; Learning fundamentals of Arrays
; Parhuam Jalalian
; 3/21/2019

COMMENT !
Write a program that stores user input strings in a 2D array. 
Then the program tells the user whether a specified string is a palindrome.
A palindrome is a string that reads the same forward and backward. 
!

INCLUDE Irvine32.inc

;Our ROW and COL
ROW = 4						
COL = 20

printTheString macro srtringAddress
push edx
mov edx, srtringAddress
call writeString
pop edx
endm

printNum macro number	
push eax
mov eax, number
call writeDec
mov al, ' '
call writeChar
pop eax
endm

.data
table			BYTE ROW dup(COL dup(0)), 0

userPrompt		BYTE "Enter text string: ", 0
printList		BYTE "List of strings", 0ah, 0dh, 0
stringPrompt	BYTE "Enter string number (-1 to end): ", 0

isPalindrome	BYTE "Palindrome", 0ah, 0dh, 0
notPalindrome	BYTE "Not a Palindrome", 0ah, 0dh, 0


.code
main PROC
sub esp, 4
push OFFSET printList
push OFFSET userPrompt
push OFFSET table
call fillArray
pop ecx		


theloop:
printTheString OFFSET stringPrompt
call readInt
cmp eax, -1		; end loop if -1
je endofProgram
cmp eax, 0
jle theloop
cmp eax, ecx
ja theloop


sub esp, 4   		
push OFFSET table 	; send table
dec eax
push eax		
call checkString
pop eax
cmp eax, 0
je notPalin
printTheString OFFSET isPalindrome	; print if palindrome
jmp endOfLoop

notPalin:
printTheString OFFSET notPalindrome	; print if not palindrome

endOfLoop:
jmp theloop

endofProgram:
exit
main ENDP

fillArray PROC
push ebp
mov ebp,esp
pushad
mov edx, [ebp+8]	
mov esi, ROW		; loop counter
xor ebx, ebx  

itFill:
printTheString[ebp+12]	
mov ecx, COL
call readString
cmp BYTE PTR [edx], 0	; end if user hits enter
je finish
inc ebx			
add edx, COL		
dec esi			; decrease counter
jnz itFill

finish:
mov [ebp+20], ebx	
mov edx, [ebp+16]	
mov ecx, ebx		
mov esi, [ebp+8]        
call printArray
popad
pop ebp
ret 12
fillArray ENDP

printArray PROC
printTheString edx
mov edx, 1

printWholeThing:
printNum ebx
inc ebx
printTheString esi
call crlf
add esi, COL
loop printWholeThing
ret
printArray ENDP


checkString PROC
push ebp
mov ebp, esp
pushad

;check Palindrome
mov edi, [ebp+12]
mov eax, COL
mul DWORD PTR [ebp+8]
add edi, eax		
mov al, 0		
mov ecx, COL		
mov edx, edi	
repne scasb		; see if 0/null in end
sub edi, 2		
mov ecx, edi		
sub ecx, edx		
inc ecx			
shr ecx, 1		; number of compares
cmp ecx, 0		; if there is 1 char, consider it palindrome
je ifTrue		
mov esi, edx	

theSame:
cmpsb			; compare front/behind
jne stopLoop
sub edi, 2		
loop theSame

stopLoop:
cmp ecx, 0
jne ifFalse

ifTrue:
mov DWORD PTR [ebp+16], 1
jmp theEnd

ifFalse:
mov DWORD PTR [ebp+16],0

theEnd:
popad
pop ebp
ret 8
checkString ENDP

END main