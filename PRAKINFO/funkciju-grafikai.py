import matplotlib.pyplot as plt
import numpy as np
# Pirmas etapas
X = np.linspace(-6, 6, 500)
Y = np.sin(pow(X,2))
y = (-1, 1, 0.5)

plt.plot(X, Y, linestyle = "dotted")
plt.title("$\t{f}(x) = \sin (x^2)$" )
plt.ylabel("y")
plt.xlabel("x")
plt.xlim(-6, 6)
plt.yticks(np.arange(-1, 1.1, 0.5))
plt.show()
plt.savefig("sinx2.pdf")
plt.close()
# # Pirmo etapo pabaiga

limX = np.linspace(-5, 5, 1001)
plt.ylim(-15, 15)
plt.xlim(-5, 5)
plt.xlabel("x")
plt.ylabel("y")
plt.title("Hiperboles")
f1 = 1 / np.cbrt(limX)
plt.plot(limX, f1, label = r'$f_{1}(x) = \frac{1}{\sqrt[3]{x}}$')
f2 = 1 / limX
plt.plot(limX, f2, linestyle = "dashed" ,label = r'$f_{2}(x) = \frac{1}{x}$')
f3 = 1 / pow(limX, 2)
plt.plot(limX, f3, linestyle = "dotted", label = r'$f_{3}(x) = \frac{1}{x^2}$')
plt.legend()
plt.show()
plt.savefig("hiperboles.pdf")
plt.close()