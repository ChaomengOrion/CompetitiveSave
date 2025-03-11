#include <bits/stdc++.h>
#if 0
int gI = -1;

class Book {
public:
    int m{3};
    Book() {
        std::cout << gI << ":"
                  << "default constructor\n";
    }
    Book(Book&& b) {
        std::cout << gI << ":"
                  << "move constructor\n";
    }
    Book(const Book& b) {
        std::cout << gI << ":"
                  << "copy constructor\n";
    }

    Book& operator=(const Book&) {
        std::cout << gI << ":"
                  << "copy assigment\n";
        return *this;
    }
    Book& operator=(Book&&) {
        std::cout << gI << ":"
                  << "move assignment\n";
        return *this;
    }
};
void main2() {
    gI = 0;
    std::cout << gI << "-";
    Book bb = Book(); // prvalue直接初始化 default constructor
    gI = 1;
    std::cout << gI << "-";
    Book b; //  default constructor
    gI = 2;
    std::cout << gI << "-";
    b = Book(); // 移动 pravlue

    gI = 3;
    std::cout << gI << "-m1:";
    bb = std::move(b); // lvalue转换成xvalue，然后移动
    std::cout << gI << "-m2:";
    bb = std::move(std::move(b)); // lvalue转换成xvalue，然后移动

    gI = 4;
    std::cout << "copy?" << '\n';
    bb = b;

    gI = 5;
    std::cout << "new copy?" << '\n';
    Book bbb = b;

    gI = 6;
    std::cout << "new copy move?" << '\n';
    Book bbbb = std::move(b);
}
#endif
class ST {
public:
    int size = 0;
    char* ptr = nullptr;
    ST(int size)
        : size(size) {
        std::cout << "[malloc ctor]: " << size << '\n';
        ptr = new char[size];
    }
    ST(std::string s)
        : ST(s.size()) {
        set(s);
    }
    ST(const ST& source)
        : ST(source.size) {
        std::cout << "[copy ctor]\n";
        for (int i = 0; i < size; i++) {
            ptr[i] = source.ptr[i];
        }
    }
    ST(ST&& source) {
        std::cout << "[move ctor]\n";
        ptr = source.ptr;
        size = source.size;
        source.ptr = nullptr;
        source.size = 0;
    }
    ST& operator=(ST&& source) {
        std::cout << "[move assigment]\n";
        ptr = source.ptr;
        size = source.size;
        source.ptr = nullptr;
        source.size = 0;
        return *this;
    }
    void set(std::string s) {
        for (int i = 0; i < size; i++) {
            ptr[i] = s[i];
        }
    }
    void print() const {
        std::cout << "Size: " << size << ", Ptr: " << (void*)ptr << ": [";
        for (int i = 0; i < size; i++) {
            std::cout << ptr[i];
        }
        std::cout << "]\n";
    }
};

std::ostream operator<<(std::ostream os, ST& s) {
    for (int i = 0; i < s.size; i++) {
        os << s.ptr[i];
    }
    return os;
}

int main() {
    ST st("!12?abc");
    st.print();
    ST st2 = st;
    st2.print();
    auto st3 = std::move(st2);
    st3.print();
    st.print();
    st2.print();
    st3 = std::move(st);
    st3.print();
    st.print();
    st2.print();

    std::cout << "==========" << '\n';
    std::cout << st3 << '\n';
}