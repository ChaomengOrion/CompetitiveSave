#include <iostream>

using namespace std;

int main() {
    static int count = 1;
    cout << "main called " << count++ << " times" << endl;

    // Limit the recursion to prevent stack overflow
    if (count <= 10) {
        main();
    }

    return 0;
}