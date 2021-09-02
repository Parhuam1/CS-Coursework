TITLE  Assignment 4: Calculate sum of integer sequences, flag evaluation
		
; Don't forget this beginning documentation block
; Name: Parhuam Jalalian

; Part 1 (10 pts): Calculate sum of integer sequences
INCLUDE Irvine32.inc

.data
NPrompt BYTE "Enter the number of integers: ", 0     ; Prompts
aPrompt BYTE "Enter the start integer: ", 0
dPrompt BYTE "Enter the difference between integers: ", 0

NOutput BYTE "N = ", 0         ;Output
aOutput BYTE ", a = ", 0
dOutput BYTE ", d = ", 0
sumOutput BYTE ", sum = ", 0


.code
main PROC

mov edx, OFFSET NPrompt    ;print prompt, store N in di
call WriteString
call readDec
mov di, ax

mov edx, OFFSET aPrompt	   ;print prompt, store a in bx
call WriteString
call readDec
mov bx, ax

mov edx, OFFSET dPrompt    ;print prompt, store d in cx
call WriteString
call readDec
mov cx, ax


;Calculations
mov ax, 2			
mul bx		; dx:ax = 2 * a
mov bx, ax  ; bx = 2 * a

mov bp, di  ; bp = N
sub bp, 1   ; bp = N - 1
mov ax, cx  ; ax = d
mul bp      ; dx:ax = (N-1) * d
			; i.e: ax = (N-1) * d

add ax, bx  ; ax = 2a +(N-1)d
			;      bx   eax
movzx edi, di ;0 the high 16 bits of this 32 bit registor
movzx eax, ax ;0 the high 16 bits of this 32 bit registor
mul edi     ; edx:eax = N * (2a + (N-1)d)

mov ecx, 2
div ecx     ; eax = eax/ecx.  eax = N * (2a + (N-1)d)/2, which is our final result
mov ebp, eax ; save eax into another register, because eax is about to be overwritten by writeDec etc


;Result
;Output N, a, d, and sum

mov edx, OFFSET NOutput        
call WriteString
mov ax, di
call writeDec

mov edx, OFFSET aOutput
call WriteString
mov ax, bx
call writeDec

mov edx, OFFSET dOutput
call WriteString
mov ax, cx
call writeDec

mov edx, OFFSET sumOutput
call WriteString
mov eax, ebp
call writeDec


	exit	
main ENDP

END main


COMMENT !
Part 2 (5pts): Flag evaluation
Assume ZF, SF, CF, OF are all clear at the start, and the 3 instructions below run one after another. 
a. fill in the value of all 4 flags after each of the add and the sub instructions runs 
b. explain why CF and OF flags have that value 
   Your explanation should not refer to specific signed / unsigned data values 
   (example of what not to use: the result -12 fits within a byte)
   the ALU doesn't differentiate signed vs. unsigned data and yet it can set the flags.

mov al, 70h 

add al, 40h    
												
	0111 0000										
+	0100 0000			    						
-------------			 				     
    1011 0000										

; a. ZF = 0   SF = 1    CF = 0   OF = 1
; b. explanation for CF: there is no carry out
;    explanation for OF: there is overflow because there is no carry out but carry in

sub al, 0F0h   
																		
	1011 0000    ->   1011 0000     
-	1111 0000		+ 0001 0000
--------------      -------------
					  1100 0000

; a. ZF =  0  SF =  1  CF = 0  OF = 0
; b. explanation for CF: there is no carry out
;    explanation for OF: there is no carry out and no carry in but there is already a one so how does it know its not a carry in? 

!