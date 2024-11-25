x = 1
for k in range(1, int(10)):
    #print(k, bin(k)[2:], bin(x)[2:], k * x, bin(k * x)[2:], (k * x) ^ x, bin((k * x) ^ x)[2:], ((k * x) ^ x) - (k * x))
    print(k, (k * x) ^ x)
