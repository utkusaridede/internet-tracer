from collections import Counter
import matplotlib.pyplot as plt
import numpy as np

readFile = open("signals", "r")

lines = readFile.readlines()

listOsman = []

for i in xrange(0, len(lines)):
	listOsman.append(lines[i].split('|'))

x = np.arange(len(listOsman))

macAdresses = []
packetS = []

for i in xrange(0, len(listOsman)):
	macAdresses.append(listOsman[i][0])
	packetS.append(int(listOsman[i][1]))

plt.bar(x, packetS)
plt.xticks(x + 0.5, macAdresses, rotation=90)

plt.xlabel('Unique Devices')
plt.ylabel('Strength')
plt.title('Signal Strengths')

plt.show()