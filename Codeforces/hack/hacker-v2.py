import random

def generate_input(n, k, max_value):
    # 生成数组 a 和 b，确保所有元素唯一
    a = [random.randint(0, max_value) for i in range(0, n)]
    
    b = [random.randint(a[i] + 1, max_value + 1) for i in range(0, n)]
    
    print(1)  # t = 1
    print(n, k)
    print(" ".join(map(str, a)))
    print(" ".join(map(str, b)))

if __name__ == "__main__":
    # 参数设置
    n = 200000
    k = 200000
    max_value = 2000000000  # 确保 b_list 不与 a_list 重叠
    random.seed(155)
    generate_input(n, k, max_value)