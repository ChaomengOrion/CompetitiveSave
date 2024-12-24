import random

def generate_input(n, k, max_value):
    # 生成数组 a 和 b，确保所有元素唯一
    a = [random.randint(1, max_value // 2) for i in range(0, n)]
    b = [random.randint(max_value // 2, max_value + 1) for i in range(0, n)]
    
    # 增加随机性，打乱 a 和 b 列表
    random.shuffle(a)
    random.shuffle(b)
    
    print(n, k)
    print(" ".join(map(str, a)))
    print(" ".join(map(str, b)))

if __name__ == "__main__":
    # 参数设置
    t = 10000
    n = 20
    k = 20
    max_value = 2000000000  # 确保 b_list 不与 a_list 重叠
    random.seed(776)
    print(t)
    for _ in range(t):
        generate_input(n, k, max_value)