a = list(map(int, input().strip().split(' ')))

for n in range(1, 51):
    ans = []
    for m in range(0, len(a)):
        if a[m] == n:
            ans.append(m)
    print(n, ans, ans[1] - ans[0])