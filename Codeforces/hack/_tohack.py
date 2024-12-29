for tt in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    ans = set()
    ans.add(0)  
    presum = 0
    done = {0}
    for num in a:
        presum += num
        for p in list(done):
            ans.add(presum - p)
        done.add(presum)
    res = sorted(list(ans))
    print(len(res))
    for num in res:
        print(num, end=' ')
    print()