arr = [1, 3, 4, 11]
def test(x):
    for i in range(len(arr) - 1, -1, -1):
        if (x < arr[i]): return len(arr) - i - 1
        x ^= arr[i]
        print(arr[i], x)
    return len(arr)

for i in range(1, 18):
    print(f"test {i}:", test(i)) 