import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("Data.dat")
grid = np.reshape(data, (101, 200))


plt.figure()
plt.imshow(grid)
plt.xlabel("Iteraccion")
plt.ylabel("Posicion")
plt.colorbar(label="Temperatura")
plt.savefig("plot_grad.png")


X=[]
Y=[]

for i in range(101):
    Y.append(grid[i][199])
    X.append(i*0.02)


plt.figure()
plt.plot(X,Y)
plt.xlabel("Posicion")
plt.ylabel("Temperatura")
plt.savefig("plot_norm.png")
