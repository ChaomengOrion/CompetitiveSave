import random

def generate_input(n, m, q, max_value):
    # 生成数组 a 和 b
    a = [i * (1 if i % 2 == 0 else -1) for i in range(1, n + 1)]
    b = [i * (-1 if i % 7 == 0 else 1) for i in range(1, m + 1)]
    
    # 生成查询
    queries = [196560 for _ in range(0, q)]
    
    # 输出数据
    print(n, m, q)
    print(" ".join(map(str, a)))
    print(" ".join(map(str, b)))
    for query in queries:
        print(query)

if __name__ == "__main__":
    # 参数设置
    n = 200000  # 数组 a 的长度
    m = 200000  # 数组 b 的长度
    q = 50000   # 查询的数量
    max_value = 200000  # 数组元素的最大值
    random.seed(114514)
    generate_input(n, m, q, max_value)