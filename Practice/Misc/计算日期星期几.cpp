#include <iostream>

using namespace std;

int main()
{

    int y, m, d;

    while (cin >> y >> m >> d) {

        if (m == 1) {
            y = y - 1;
            m = 13;
        } else if (m == 2) {
            y = y - 1;
            m = 14;
        }
        cout << (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7 + 1 << endl;
    }
    return 0;
}