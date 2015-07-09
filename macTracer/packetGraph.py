from collections import Counter
import matplotlib.pyplot as plt
import numpy as np

packetSizes = open("data/packetSizes", "r")

lines = packetSizes.readlines()

listOsman = []

for i in xrange(0, len(lines)):
	listOsman.append(lines[i].split('|'))

x = np.arange(len(listOsman))

print listOsman

macAdresses = []
packetS = []

for i in xrange(0, len(listOsman)):
	macAdresses.append(listOsman[i][0])
	packetS.append(int(listOsman[i][1]))

plt.bar(x, packetS)
plt.xticks(x + 0.5, macAdresses, rotation=90)

plt.xlabel('Companies')
plt.ylabel('Frequencies')
plt.title('Company Distrubutions')

plt.show()