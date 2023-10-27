import sys
import math

def Validation(number):
    value = None
    try:
        value = int(number)
    except ValueError:
        pass
    return value

print("N-tojo laipsnio saknies traukimo is skaiciaus programa.")
a = input("Iveskite daugikli pries sakni (1 jei nera): ")
a = Validation(a)
if a == None:
    print("Netinkama vartotojo ivestis, reikia ivesti sveikaji skaiciu.")
    sys.exit(0)
n = input("Iveskite saknies laipsni: ")
n = Validation(n)
if n == None or n < 2:
    print("Netinkama vartotojo ivestis, reikia ivesti sveikaji skaiciu, ne mazesni uz 2.")
    sys.exit(0)
b = input("Iveskite posakni: ")
b = Validation(b)
if b == None:
    print("Netinkama vartotojo ivestis, reikia ivesti sveikaji skaiciu.")
    sys.exit(0)
elif n%2==0 and b<0:
    print("Lyginio laipsnio sakni galime traukti tik is sveikojo skaiciaus.")
    sys.exit(0)
    

for posak in range(1+b):
    for daugiklis in range(b):
        if pow(daugiklis,n) * posak == b:
            a *= daugiklis
            b = posak
            break

if a == 1:
    print(n, "√", b)
elif b == 1:
    print(a)
else:
    print(a,"*",n,"√",b)
    
