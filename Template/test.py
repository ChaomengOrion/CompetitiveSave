def test(n):
    print(1 << n)
    if n % 2:
        print(f'input {n} % 2 = 1')

test(4)