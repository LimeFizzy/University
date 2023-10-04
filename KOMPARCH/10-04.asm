.model small
.stach 100h
.data
    buffer db 10, ?
.code
Start:
    mov ax, @data
    mov ds, ax
END Start