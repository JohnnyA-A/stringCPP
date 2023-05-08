.586
.MODEL FLAT, STDCALL
PUBLIC asm_fun
_DATA SEGMENT
	mas db 'Memory good', 0
_DATA ENDS

_TEXT SEGMENT
asm_fun PROC par1:DWORD, par2:DWORD
	mov EAX, par1
	mov EBX, par2
	add EAX, EBX
	ret
asm_fun ENDP
_TEXT ENDS
END