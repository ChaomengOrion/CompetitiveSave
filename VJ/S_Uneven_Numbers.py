N = int(input())
n = 1
rest = N
cnt = 0
while (n <= N):
    l = 0
    tn = n
    while tn > 0:
        l += 1
        tn //= 10
    if l % 2 == 1:
        cnt += min(9 * n, rest)
    rest = max(0, rest - 9 * n)
    n *= 10
print(cnt)