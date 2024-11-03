import numpy as np
import matplotlib.pyplot as plt
#from mpl_toolkits.mplot3d import Axes3D

# Definir la función
def funcion(x, y):
    return np.abs(x * y)**1.3 * np.exp(-np.sqrt(x**2 + y**2) / np.sqrt(2))

# Crear una malla de puntos
x = np.linspace(-5, 5, 100)
y = np.linspace(-5, 5, 100)
x, y = np.meshgrid(x, y)
z = funcion(x, y)

# Crear la figura
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Graficar la superficie
surface = ax.plot_surface(x, y, z, cmap='viridis')

# Añadir una barra de color
fig.colorbar(surface, ax=ax, shrink=0.5, aspect=5)

# Añadir etiquetas y título
ax.set_xlabel('Eje X')
ax.set_ylabel('Eje Y')
ax.set_zlabel('Masa')
ax.set_title('Gráfico de la función Masa')

# Mostrar el gráfico
plt.show()
