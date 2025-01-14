#include <bits/stdc++.h>
int main() {
    struct A {
        int v;
        int nxt;
        void test();
    };
    std::vector<A> tree(11);
    void A::test(const A& a) {
        tree[a.nxt] = a.v;
    };
    return 0;
}