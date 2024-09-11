#include <bits/stdc++.h>

int main()
{
    int _;
    std::string s;
    std::cin >> _ >> s; // 用不上n

    auto handle = [&](auto handle, int start, int end) -> void {
        int type = s[start] == '1', i = start;
        while (++i < end) if (s[i] == '1' != type) type = -1;

        if (end - start >= 2) {
            handle(handle, start, (start + end) / 2);
            handle(handle, (start + end) / 2, end);
        }

        switch (type) {
            case -1:
                std::cout << 'F';
                break;
            case 0:
                std::cout << 'B';
                break;
            case 1:
                std::cout << 'I';
                break;
        }
    };

    handle(handle, 0, s.size());
    std::cout << std::endl;
}