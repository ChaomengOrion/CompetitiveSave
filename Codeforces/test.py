import math
x = 0
#for i in range(1, 10000):
for i in range(10000, 0, -1):
    x += i
    if (math.sqrt(x) == int(math.sqrt(x))): print(i, x, math.sqrt(x))