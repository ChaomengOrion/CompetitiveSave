arr = [1]
print(arr)
for i in range(80):
    nxt = []
    nxt.append(arr[0])
    for j in range(1, len(arr)):
        nxt.append(arr[j] ^ arr[j - 1])
    nxt.append(arr[-1])
    print(nxt)
    arr = nxt