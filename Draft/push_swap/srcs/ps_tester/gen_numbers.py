import random
import numpy as np
import sys

n = int(sys.argv[1])
# nbs = ["{} ".format(random.randint(-500, 500)) for i in range(n)]
nbs = list(np.random.permutation(np.arange(-1000,1000))[:n])

file = open('numbers.txt', 'w')
for index, nb in enumerate(nbs):
    file.write(str(nb))
    file.write(' ')
file.close()
