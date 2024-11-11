import sys
def one(n, arr, copyarr):
    array = [[None for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            array[j][n - i - 1] = arr[i][j]
    if array == copyarr: return True
    else: return False
def two(n, arr, copyarr):
    array = [[None for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            array[n - i - 1][n - j - 1] = arr[i][j]
    if array == copyarr: return True
    else: return False
def three(n, arr, copyarr):
    array = [[None for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            array[n - j - 1][i] = arr[i][j]
    if array == copyarr: return True
    else: return False
def four(n, arr, copyarr):
    array = [[None for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            array[i][n - j - 1] = arr[i][j]
    if array == copyarr:return True
    else: return False
def five(n, arr, copyarr):
    array = [[None for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            array[i][n - j - 1] = arr[i][j]
    if one(n, array, copyarr): return True
    elif two(n, array, copyarr): return True
    elif three(n, array, copyarr): return True
    else: return False

def inp():
    r = str()
    try:
        while True:
            c = sys.stdin.read(1)
            if c not in ['\r', '\n']:
                r += c
            elif c == '\r':
                sys.stdin.read(1)
                break
            else:
                break
    finally:
        print(r)
        return r

n = int(inp())
arr = []
for i in range(n):
    arr.append(list(inp()))
copyarr = []
for i in range(n):
    copyarr.append(list(inp()))
#print(arr)
#print(copyarr)
if arr == copyarr: print(6)
elif one(n, arr, copyarr): print(1)
elif two(n, arr, copyarr): print(2)
elif three(n, arr, copyarr): print(3)
elif four(n, arr, copyarr): print(4)
elif five(n, arr, copyarr): print(5)
else: print(7)