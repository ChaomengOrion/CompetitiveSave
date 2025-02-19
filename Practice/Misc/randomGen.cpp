#include <bits/stdc++.h>

typedef int MyFuc (float, bool);

int func1(float, bool);
int func2(float, bool);
int func3(float, bool);

MyFuc* ss[3] = {func1, func2, func3};

void test() {
    (ss[0])(2.3, false);
    (*ss[0])(2.3, false);
}

static int last = 0;

int getNext(int d) {
    int digit = 0;
    do {
        last = (25173 * last + 13849) % 65536;
        int temp = last;
        digit = 0;
        while (temp > 0) {
            temp /= 10;
            digit++;
        }
    } while (digit != d);
    return last;
}

int main() {
    int d, n;
    while (std::cin >> d >> n) {
        last = 0;
        while (n--) {
            int a = getNext(d), b = getNext(d);
            printf("%d+%d=%d, %d-%d=%d, %d*%d=%d, %d/%d=%d\n", a, b, a+b, a, b, a-b, a, b, a*b, a, b, a/b);
        }
    }
}