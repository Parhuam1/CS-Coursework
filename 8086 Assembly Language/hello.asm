; hello world in assembly

INCLUDE Irvine32.inc
.data

string BYTE	"Six", 0
stringLength DWORD 3
table  BYTE 48 DUP (' '), "0123456789", 7 DUP (' ')
	   BYTE "abcdefghijklmnopqrstuvwxyz", 6 DUP (' ')
	   BYTE "abcdefghijklmnopqrstuvwxyz", 133 DUP (' ')
	
.code
main proc

mov ecx, stringLength
lea ebx, table
lea esi, string
lea edi, string

forIndex: lodsb
xlat
stosb
loop forIndex

call writeString


   exit
main endp

end main