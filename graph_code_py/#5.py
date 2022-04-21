import numpy as np
import matplotlib.pyplot as plt

file = open('/home/ivankhripunov/CLionProjects/container_lab/cmake-build-debug/#5.txt', 'r')

size = np.arange(0, 10000, 1)
vector = []
subvector = []

data = file.readlines()

for line in data:
    array = [float(i) for i in line.split()]
    vector.append(array[0])
    subvector.append(array[1])

p_vector = np.polyfit(size, vector, 0)
approx_vector = np.polyval(p_vector, size)
print(p_vector)

p_subvector = np.polyfit(size, subvector, 0)
approx_subvector = np.polyval(p_subvector, size)
print(p_subvector)

fig, ax = plt.subplots()

ax.plot(size, vector, label="forward_list")
ax.plot(size, subvector, label="subforward_list")
ax.set_ylim(0, 1e4)
ax.plot(size, approx_subvector, "g--", label="Аппроксимация subforward_list y = 1661")
ax.set_title("Добавление в начало списка")
ax.set_xlabel("Размер контейнера")
ax.set_ylabel("Время, наносекунды")
plt.legend()

fig2, ax2 = plt.subplots()

ax2.plot(size, vector)
ax2.plot(size, approx_vector, "r--", label="Аппроксимация y = 1535")
ax2.set_ylim(0, 1e4)
ax2.set_title("Добавление в начало списка (только forward_list)")
ax2.set_xlabel("Размер контейнера")
ax2.set_ylabel("Время, наносекунды")
plt.legend()

plt.show()
