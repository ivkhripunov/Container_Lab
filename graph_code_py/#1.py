import numpy as np
import matplotlib.pyplot as plt

file = open('/home/ivankhripunov/CLionProjects/container_lab/cmake-build-debug/#1.txt', 'r')

size = np.arange(1, 4097, 1)
vector = []
subvector = []

data = file.readlines()


for line in data:
    array = [float(i) for i in line.split()]
    vector.append(array[0])
    subvector.append(array[1])

fig, ax = plt.subplots()

ax.plot(size, vector)
ax.set_xlabel("Номер итерации pushback")
ax.set_ylabel("Капасити")
ax.plot(size, subvector)
ax.set_title("График capacity от i")

plt.show()
