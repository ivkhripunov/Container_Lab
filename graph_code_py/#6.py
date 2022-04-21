import numpy as np
import matplotlib.pyplot as plt

file = open('/home/ivankhripunov/CLionProjects/container_lab/cmake-build-debug/#6.txt', 'r')

size = np.arange(10000, 100000, 1)
#size = reversed(size)
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
ax.plot(size, approx_subvector, "g--", label="Аппроксимация subforward_list y = 9052")
ax.set_ylim(0, 6e4)
ax.set_title("Удаление из начала списка")
ax.set_xlabel("Размер контейнера")
ax.set_ylabel("Время, наносекунды")
plt.legend()

fig2, ax2 = plt.subplots()

ax2.plot(size, vector)
ax2.plot(size, approx_vector, "r--", label="Аппроксимация y = 4797")
ax2.set_ylim(0, 6e4)
ax2.set_title("Удаление из начала списка (только forward_list)")
ax2.set_xlabel("Размер контейнера")
ax2.set_ylabel("Время, наносекунды")
plt.legend()

plt.show()