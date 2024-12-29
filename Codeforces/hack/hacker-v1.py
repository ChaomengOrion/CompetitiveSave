import random

def generate_input(n, max_value):
    a = [1 for i in range(0, n // 2)] + [max_value] + [1 for i in range(n // 2, n - 1)]
    
    print(n)
    print(" ".join(map(str, a)))

if __name__ == "__main__":
    # 参数设置
    t = 1
    n = 200000
    max_value = 1000000000
    print(t)
    for _ in range(t):
        generate_input(n, max_value)