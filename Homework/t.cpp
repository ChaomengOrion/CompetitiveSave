#include <bits/stdc++.h>

using namespace std::chrono;

inline std::string toBin(long long n) {
    std::string s;
    while (n > 0) {
        s += (char)(n & 1) + '0';
        n >>= 1;
    }
    std::reverse(s.begin(), s.end());
    return s;
}

int main()
{
    std::string s;
    const long long INPUT = 4235235253235545345;
    std::cout << "\033[1;36mTest num: " << INPUT << "\033[m\n";
    std::cout << "\033[1;33mtoBin output: " << toBin(INPUT) << "\033[m\n";
    std::cout << "\033[1;33mbitset output: " << std::bitset<64>(INPUT).to_string().substr(std::max(0, 63 - (int)log2l(INPUT))) << "\033[m\n";

    auto start1 = system_clock::now();
    for (int i = 0; i < 1E7; i++) {
        s = toBin(INPUT);
    }
    auto end1  = system_clock::now();

    auto start2 = system_clock::now();

    for (int i = 0; i < 1E7; i++) {
        s = std::bitset<64>(INPUT).to_string().substr(std::max(0, 63 - (int)log2l(INPUT)));
    }
    auto end2  = system_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    std::cout <<  "toBin Cost "  << double(duration1.count()) * microseconds::period::num / microseconds::period::den << " s" << std::endl;
    std::cout <<  "bitset Cost "  << double(duration2.count()) * microseconds::period::num / microseconds::period::den << " s" << std::endl;
}