from collections import Counter
import matplotlib.pyplot as plt
import numpy as np

readFile = open("signals", "r")

lines = readFile.readlines()

x = np.arange(len(lines))

plt.plot(lines)

plt.xlabel('Unique Devices')
plt.ylabel('Strength')
plt.title('Signal Strengths')

plt.show()