
for n in range(719, 720):
    for d in range(1, 10):
        s = str(d) * n
        s = int(s)
        if s % 9 == 0:
            print(s, len(str(s)))
