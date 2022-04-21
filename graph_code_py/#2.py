import numpy as np
import matplotlib.pyplot as plt

file = open('/home/ivankhripunov/CLionProjects/container_lab/cmake-build-debug/#2.txt', 'r')

size = np.arange(1000, 100001, 1000)
vector = []
subvector = []

data = file.readlines()

for line in data:
    array = [float(i) for i in line.split()]
    vector.append(array[0])
    subvector.append(array[1])

p_vector = np.polyfit(size, vector, 1)
approx_vector = np.polyval(p_vector, size)
print(p_vector)

p_subvector = np.polyfit(size, subvector, 1)
approx_subvector = np.polyval(p_subvector, size)
print(p_subvector)

fig, ax = plt.subplots()

ax.plot(size, vector, label="Vector")
ax.plot(size, subvector, label="Subvector")
ax.plot(size, approx_subvector, "g--", label="Аппроксимация y = 2.13 + 2374")
ax.set_title("Вставка в произвольное место контейнера")
ax.set_xlabel("Размер контейнера")
ax.set_ylabel("Время, наносекунды")
plt.legend()

fig2, ax2 = plt.subplots()

ax2.plot(size, vector)
ax2.plot(size, approx_vector, "r--", label="Аппроксимация y = 3.3e-2 * x + 1.25e3")
ax2.set_title("Вставка в произвольное место контейнера (только vector)")
ax2.set_xlabel("Размер контейнера")
ax2.set_ylabel("Время, наносекунды")
plt.legend()

plt.show()
