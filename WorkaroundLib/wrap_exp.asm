PUBLIC	exp
EXTRN __imp_exp:PROC
_TEXT	SEGMENT
exp	PROC
	jmp         qword ptr [__imp_exp]
exp ENDP
_TEXT	ENDS
END
