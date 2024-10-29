#include <bits/stdc++.h>

long long cnt = 0;

void foo(int b) {
    cnt += b;
    foo(b);
}

int main() {
    foo(1);
}
