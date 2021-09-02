Title Assignment 7

COMMENT !
*****************
date: 11/29/2019
*****************
!

include irvine32.inc
; ===============================================
.data
  
theArray	DWORD 40 dup(?)
arrayLength DWORD ?

firstString	BYTE "Enter up to 40 unsigned dword integers. To end the array, enter 0.", 0
secondString	BYTE	"After each element press enter: ", 0

initialString	 BYTE "Initial array: ", 0
descendingString BYTE "Array sorted in descending order: ", 0
continueString	 BYTE "Press any key to continue...", 0

;=================================================
.code
main proc
;Print Intro
mov edx, offset firstString
call writeString
call crlf
mov edx, offset secondString
call writeString
call crlf

;Read Array
push offset theArray
call enter_elem
pop arrayLength
call crlf
call crlf

;Show Array
mov edx, offset initialString
call writeString
call crlf
push offset theArray
push arrayLength
call print_arr
call crlf

;Sort Array
push offset theArray
push arrayLength
call sort_arr

;Array after sort
mov edx, offset descendingString
call writeString
call crlf
push offset theArray
push arrayLength
call print_arr
call crlf
	
;Pause 
mov edx, offset continueString
call writeString
call readChar
  
   exit
main endp

; ================================================
; void enter_elem(arr_addr)
;
; Input:
;   ARR_ADDRESS THROUGH THE STACK
; Output:
;   ARR_LENGTH THROUGH THE STACK
; Operation:
;   Fill the array and count the number of elements
;
enter_elem proc
push ebp
mov ebp, esp
push ebx
push ecx
push eax
mov ebx, [ebp + 8]  
xor ecx, ecx
; If ecx is less than 40, go until user types 40 inputs or
; user types in 0 to end loop

L1:
cmp ecx, 40
jGE L2
call readInt
cmp eax, 0
jE L2
mov [ebx], eax
add ebx, DWORD
inc ecx
jmp L1
	
L2:	
pop eax
mov [ebp+8], ecx 
pop ecx
pop ebx
pop ebp
ret
enter_elem endp

; ================================================
; void print_arr(arr_addr,arr_len)
;
; Input:
;    Array length and Array Address using stack.
; Output:
;   No return.
; Operation:
;  Print Array.
;

print_arr proc
push ebp
mov ebp, esp
push edx
push ecx
push ebx
push eax

mov edx, [ebp + 12] 
mov ecx, [ebp + 8]
xor ebx, ebx

; Print each element in array
L3:
cmp ebx, ecx
jGE L4

mov eax, [edx]
call writeDec
mov eax, ' '
call writeChar
add edx, DWORD
inc ebx
jmp L3

L4:
pop eax
pop ebx
pop ecx
pop edx
pop ebp
ret 8
print_arr endp

; ================================================
; void sort_arr(arr_addr,arr_len)
;
; Input:
;    Array length and Array Address using stack.
; Output:
;    No return.
; Operation:
;   Print Array.
;

sort_arr proc

push ebp
mov ebp, esp
push edx
push ecx
push ebx
push eax
push edi
	
; Array length
mov ecx, [ebp + 8]
mov eax, ecx
xor edx, edx
mov ecx, 4
mul ecx
mov ecx, eax

; Offset
mov edx, [ebp + 12] 

; Inner loop
xor ebx, ebx 

; Outer Loop
xor eax, eax  

; Location
xor edi, edi  

; Compare and swap of what is being compared and checked
; using the index saved in esi, eax, and ebx
L5:
cmp eax, ecx
jGE L6

mov ebx, eax
mov edi, ebx

searchMaxIndex:
cmp ebx, ecx
jGE outSearch
push eax
mov eax, [edx + ebx]
cmp eax, [edx + edi]
pop eax
jLE notMax
mov edi, ebx
notMax:
add ebx, dword
jmp searchMaxIndex
outSearch:
		
add edx, eax
push edx
sub edx, eax

add edx, edi
push edx
sub edx, edi
call compare_and_swap

add eax, dword
jmp L5

L6:
pop edi
pop eax
pop ebx
pop ecx
pop edx
pop ebp
ret 8 
sort_arr endp

; ===============================================
; void compare_and_swap(x_addr,y_addr)
;
; Input:
;   X, Y address 
; Output:
;   No return.
; Operation:
;  Compare, swap when x < y
;

compare_and_swap proc

push ebp
mov ebp, esp
push eax
push ebx
push ecx
push edx
mov eax, [ebp + 12] 
mov ebx, [ebp + 8]  

mov ecx, [eax] 
mov edx, [ebx] 
cmp ecx, edx
jGE L7
push eax
push ebx
call swap
L7:

pop edx
pop ecx
pop ebx
pop eax
pop ebp
ret 8
compare_and_swap endp

; =================================================
; void swap(x_addr,y_addr)
;
; Input:
;   X, Y address 
; Output:
;   No return.
; Operation:
;  Swap inputs
;

swap proc

push ebp
mov ebp, esp
push eax
push ebx
push ecx
push edx
mov eax, [ebp + 12] 
mov ebx, [ebp + 8]  
	
mov ecx, [eax] 
mov edx, [ebx] 
mov [eax], edx 
mov [ebx], ecx 

pop edx
pop ecx
pop ebx
pop eax
pop ebp
ret 8
swap endp

end main


Comment!
Enter up to 40 unsigned dword integers. To end the array, enter 0.
After each element press enter:
1
4
3
8
99
76
34
5
2
17
0


Initial array:
1 4 3 8 99 76 34 5 2 17
Array sorted in descending order:
99 76 34 17 8 5 4 3 2 1
Press any key to continue...
C:\Users\v\OneDrive\Desktop\Project32_VS2017\Debug\Project.exe 
(process 9676) exited with code 0.
To automatically close the console when debugging stops, 
enable Tools->Options->Debugging->Automatically close 
the console when debugging stops.
Press any key to close this window . . .
!
