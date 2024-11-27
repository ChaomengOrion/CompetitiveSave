#include <cmath>
#include <iostream>

using namespace std;

long long daoxv(long long a) {
    long long ans = 0;
    while (a > 0) {
        ans = ans * 10 + a % 10;
        a /= 10;
    }
    return ans;
}

bool huiwen(long long a) {
    return daoxv(a) == a;
}

int main() {
    long long a, b;
    while (cin >> a) {
        b = a;
        if (huiwen(a))
            cout << a << endl;
        else {
            for (int i = 1; i <= 16; i++) {
                b += daoxv(b);
                if (huiwen(b)) break;
            }
            if (huiwen(b))
                cout << b << endl;
            else
                cout << -1 << endl;
        }
    }
}