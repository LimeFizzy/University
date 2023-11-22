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
plt.close()
# Pirmo etapo pabaiga