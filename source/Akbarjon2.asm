.586
.MODEL FLAT, STDCALL

PUBLIC asm_fun1
_DATA SEGMENT
	StrMas db 11 dup(?) 
	dec1 dd 10
_DATA ENDS

_TEXT SEGMENT
asm_fun1 PROC par1:DWORD
	lea EBX, StrMas
	mov ECX, 11
metka1:
	mov BYTE PTR [EBX], ' '
	inc EBX
	loop metka1
	mov EAX, par1
	push EAX
	or EAX, EAX
	jns metka2
	neg EAX
metka2:
	xor EDX, EDX
	div dec1
	add EDX, '0'
	dec EBX
	mov BYTE PTR [EBX], dl
	inc ECX
	or EAX, EAX
	jnz metka2
	pop EAX
	or EAX, EAX
	jns metka3
	dec EBX
	mov BYTE PTR [EBX], '-'
	inc ECX
	metka3:
	mov EAX, EBX
	ret
asm_fun1 ENDP
_TEXT ENDS
END