from collections import Counter
import matplotlib.pyplot as plt
import numpy as np

#companyCounter = open("data/companyCounter", "w")
readFile = open("data/company", "r")

lines = readFile.readlines()

values = Counter(lines).values()
keys = Counter(lines).keys()
items = Counter(lines).items()

x = np.arange(len(items))

plt.bar(x, values)
plt.xticks(x + 0.5, keys, rotation=80)

plt.xlabel('Companies')
plt.ylabel('Frequencies')
plt.title('Company Distrubutions')

plt.show()
