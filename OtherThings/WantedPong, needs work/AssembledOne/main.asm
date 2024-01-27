extrn ExitProcess : proc
extrn GetStdHandle : proc
extrn WriteConsoleA : proc
extrn printPData : proc
extrn checkKeysP1 : proc
extrn checkKeysP2 : proc
extrn cleanScreen : proc

.data
bytesWritten QWORD 0
statement QWORD "ggg", 13, 10, 0
state EQU $ - statement
consoleAddress QWORD ?
timerLength QWORD 300
lengt QWORD 25
height QWORD 17
paddleAd1 QWORD 8
paddleAd2 QWORD 8
ballAd QWORD ?
eWS QWORD ?
full BYTE 178
empty BYTE 0
return BYTE 13
velocityX QWORD -1
velocityY QWORD -1
posX QWORD 0
posY QWORD 0
score1 QWORD 0
score2 QWORD 0
minPos QWORD 2
maxPos QWORD 15

.code

asmMain PROC
mov rcx, -11
call GetStdHandle
mov consoleAddress, rax

mov rcx, 17
lea rdx, statement
mov rax, lengt
mov bh, return
lo:
add rdx, lengt
mov [rdx], bh
inc rdx
loop lo

mov bl, full
mov posX, 12
mov posY, 8
mov rcx, lengt
add rcx, 1
imul rcx, posY
add rcx, posX
mov ballAd, rcx
mov [rcx], bl

game:
mov rcx, score1
mov rdx, score2
call printPData
mov rcx, maxPos
mov rdx, minPos
mov r8, paddleAd1
call checkKeysP1
mov paddleAd1, rax
call movePan1
mov rcx, maxPos
mov rdx, minPos
mov r8, paddleAd2
call checkKeysP2
mov paddleAd2, rax
call movePan2
mov rcx, ballAd
call calculateBall
call moveBall
;mov r10, ballAd
mov rcx, consoleAddress
mov rdx, OFFSET statement
mov r8, 3
mov r9, OFFSET bytesWritten
push 0
call WriteConsoleA
call delay
call cleanScreen
cmp score1, 10
jnl game
cmp score2, 10
jnl game 
ret
asmMain ENDP

delay PROC
mov rcx, timerLength

top:
nop
loop top
ret
delay ENDP

calculateBall PROC
mov rdx, rcx
mov rax, posX
add rax, velocityX
mov posX, rax
mov rax, posY
add rax, velocityY
mov posY, rax
mov rcx, lengt
add rcx, 1
imul rcx, posY
add rcx, posX
mov ah, BYTE PTR[rcx]
mov al, BYTE PTR[rcx+1]
cmp ah, al
je leftGo
mov ah, BYTE PTR[rcx]
mov al, BYTE PTR[rcx-1]
cmp ah, al
je rightGo
cmp posX, 0
je gol2
cmp posX, 24
je gol1
cmp posY, 0
je downGo
cmp posY, 16
je upGo
jmp gol3
upGo:
mov velocityY, -1
jmp gol3
leftGo:
mov velocityX, -1
jmp gol3
downGo:
mov velocityY, 1
jmp gol3
rightGo:
mov velocityX, 1
jmp gol3
gol1:
inc score1
mov posX, 12
mov posY, 8
mov rcx, lengt
add rcx, 1
imul rcx, posY
add rcx, posX
jmp gol3
gol2:
inc score2
mov posX, 12
mov posY, 8
mov rcx, lengt
add rcx, 1
imul rcx, posY
add rcx, posX
jmp gol3
gol3:
xchg rcx, rdx
calculateBall ENDP

moveBall PROC
mov al, [rdx]
mov ah, [rcx]
mov [rcx], al
mov [rdx], ah
mov ballAd, rdx
moveBall ENDP

movePan1 PROC
mov rcx, height
lea rdx, statement 
top:
mov bh, empty
mov [rdx], bh
add rdx, lengt
inc rdx
loop top

mov rcx, lengt
add rcx, 1
imul rcx, posY
lea rax, statement
sub rax, rcx
sub rax, rcx
mov rdx, rcx

mov rcx, 5
loby:
mov bh, full
mov [rax], bh
add rax, rdx
loop loby
movePan1 ENDP

movePan2 PROC
mov rcx, height
lea rdx, statement
add rdx, lengt
top:
mov bh, empty
mov [rdx], bh
add rdx, lengt
inc rdx
loop top

mov rcx, lengt
add rcx, 1
imul rcx, posY
lea rax, statement
add rax, lengt
sub rax, rcx
sub rax, rcx
mov rdx, rcx

mov rcx, 5
loby:
mov bh, full
mov [rax], bh
add rax, rdx
loop loby
movePan2 ENDP

END