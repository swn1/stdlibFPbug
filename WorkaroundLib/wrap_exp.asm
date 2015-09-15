PUBLIC	exp
EXTRN imp_exp:PROC
_TEXT	SEGMENT
exp	PROC
	movlhps xmm0,xmm0
	jmp         qword ptr [imp_exp]
exp ENDP
_TEXT	ENDS
END
