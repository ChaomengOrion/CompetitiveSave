#include <bits/stdc++.h>

using i64 = long long;

int main(){
    for (int i = 1; i <= 256; i++) {
        std::cout << "bin: " << std::bitset<8>(i) << std::oct << " oct: "  << i << std::hex << " hex: "  << i << std::endl;
    }
}