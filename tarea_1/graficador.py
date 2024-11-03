import pandas as pd 
import matplotlib.pyplot as plt  
import matplotlib.patches as patches


datos = pd.read_csv('tarea_1/particulas.csv')

x_cm, y_cm = (0.769527, 0.716770)

df_datos = pd.DataFrame(datos)
# Calcula b y h
b = df_datos.x.max() - df_datos.x.min() 
h = df_datos.y.max() - df_datos.y.min()
A = b*h
# Crear una nueva figura y un eje 
fig, ax = plt.subplots() 
# Crear y añadir el rectángulo al gráfico 
rect = patches.Rectangle((df_datos.x.min(), df_datos.y.min()), b, h, linewidth=3, edgecolor='r', facecolor='none') 
ax.add_patch(rect) 
# Gráfico de dispersión de los datos 
ax.scatter(df_datos.x, df_datos.y) 
# Gráfico de dispersión del centro de masas 
ax.scatter(x_cm, y_cm, c='red') 
# Añadir etiquetas y título 
plt.xlabel('Eje X') 
plt.ylabel('Eje Y')

plt.title('Sistema de 1000 particulas') 

# Mostrar el gráfico 
plt.show()

print(A)