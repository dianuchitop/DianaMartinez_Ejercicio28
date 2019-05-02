import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("Data.dat")
grid = np.reshape(data, (101, 200))
print(grid)


plt.figure()
plt.imshow(grid)
plt.xlabel("Iteraccion")
plt.ylabel("indice T")
plt.colorbar(label="Temperatura")
plt.savefig("plot.png")

