import numpy as np
import matplotlib.pyplot as plt

file = open('/home/ivankhripunov/CLionProjects/container_lab/cmake-build-debug/#7.txt', 'r')

size = np.arange(1000, 100001, 1000)
# size = reversed(size)
vector = []
forward_list = []
list = []
map = []
set = []

data = file.readlines()

for line in data:
    array = [float(i) for i in line.split()]
    vector.append(array[0])
    forward_list.append(array[1])
    list.append(array[2])
    map.append(array[3])
    set.append(array[4])

fig, ax = plt.subplots()

p_vector = np.polyfit(size, vector, 1)
approx_vector = np.polyval(p_vector, size)
print(p_vector)

p_list = np.polyfit(size, list, 1)
approx_list = np.polyval(p_list, size)
print(p_list)

p_map = np.polyfit(size, map, 1)
approx_map = np.polyval(p_map, size)
print(p_map)

p_forward_list = np.polyfit(size, forward_list, 1)
approx_forward_list = np.polyval(p_forward_list, size)
print(p_forward_list)

p_set = np.polyfit(size, set, 1)
approx_set = np.polyval(p_set, size)
print(p_set)

ax.plot(size, vector, label="vector y = 5.67x + 1.3e4")

ax.plot(size, forward_list, label="forward_list y = 15.1x - 1.9e4")

ax.plot(size, list, label="list y = 8.46x + 1.6e4")

ax.plot(size, map, label="map y = 75.9x - 9.6e5")

ax.plot(size, set, label="set y = 73.1x - 9e5")

ax.set_title("Обход контейнера")
ax.set_xlabel("Размер контейнера")
ax.set_ylabel("Время, наносекунды")

plt.legend()
plt.show()
