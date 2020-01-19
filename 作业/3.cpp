// 试编写一个程序，求出首地址为DATA的100个字的数组中的最小偶数，并把它存放在MIN地址中。
int i=0;
int curmin = 0;
while(i <= 100){
	int cur = DATA[i++];
	if(cur & 1 == 0){
		curmin = cur;
		break;
	}
}
while(i <= 100){
	int cur = DATA[i++];
	if(cur & 1 == 0 && cur < curmin){
		curmin = cur;
	}
}
MIN = curmin;

////////////////////////////////////

GETMIN:
	MOV R0, #0;
	MOV R1, #DATA;
	MOV R2, #0;
	MOV R6, #MIN;
LOOP1:
	CMP R0, #100;
	BEQ END;
	LDR R3, [R1], #1;
	ADD R0, #1;
	AND R4, R3, #1;
	CMP R4, #0;
	MOVEQ R2, R3;
	BNE LOOP1;
LOOP2:
	LDR R3, [R1], #1;
	AND R4, R3, #1;
	CMP R4, #0;
	CMPEQ R3, R2;
	MOVLT R2, R3;
	ADD R0, #1;
	CMP R0, #100;
	BNE LOOP2;
END:
	MOV R6, R2;
	MOV PC, LR;