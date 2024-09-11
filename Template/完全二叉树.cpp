#include <bits/stdc++.h>

int main() {
    std::vector<std::string> tree = { "\0", "t1", "t2L", "t2R", "t2L-3L", "t2L-3R", "t2R-3L", "t2R-3R"};
    auto log = [&](auto log, int index) -> void {
        if (2*index < tree.size()) log(log, 2*index);
        std::cout << tree[index] << std::endl;
        if (2*index+1 < tree.size()) log(log, 2*index+1);
    };
    log(log, 1);
}