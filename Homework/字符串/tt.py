cnt = dict()
while True:
    p = input()
    if p == 'q': break
    cnt[p] = cnt[p] + 1 if p in cnt else 1

maxS = ''
maxCnt = -1
for k, v in cnt.items():
    if v > maxCnt:
        maxCnt = v
        maxS = k

print(maxS, maxCnt)