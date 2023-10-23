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
input("Iveskite daugikli pries sakni (1 jei nera): ", a)
a = Validation(a)
if a == None:
    print("Netinkama vartotojo įvestis, reikia įvesti sveikąjį skaičių.")
    sys.exit(0)
input("Iveskite saknies laipsni: ", n)
n = Validation(n)
if n == None or n < 3:
    print("Netinkama vartotojo įvestis, reikia įvesti sveikąjį skaičių, didesni uz 2.")
    sys.exit(0)
input("Iveskite posakni: ", b)
b = Validation(b)
if b == None or b < 0:
    print("Netinkama vartotojo įvestis, reikia įvesti teigiama sveikąjį skaičių.")
    sys.exit(0)
