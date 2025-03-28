#include <iostream>

using namespace std;

// Complex类定义
class Complex {
private:
    double realPart;     // 实部
    double imaginaryPart; // 虚部

public:
    // 构造函数，带默认参数
    Complex(double real = 0.0, double imaginary = 0.0) 
        : realPart(real), imaginaryPart(imaginary) {
    }

    // 加法运算
    Complex add(const Complex& other) const {
        return Complex(realPart + other.realPart, 
                      imaginaryPart + other.imaginaryPart);
    }

    // 减法运算
    Complex subtract(const Complex& other) const {
        return Complex(realPart - other.realPart, 
                      imaginaryPart - other.imaginaryPart);
    }

    // 打印复数
    void print() const {
        cout << "(" << realPart << " + " << imaginaryPart << "i)";
    }
};

// 测试程序
int main() {
    // 创建复数对象
    Complex c1(2.5, 3.7);
    Complex c2(1.2, 4.1);
    Complex c3; // 使用默认构造函数

    // 打印原始复数
    cout << "c1 = ";
    c1.print();
    cout << endl;

    cout << "c2 = ";
    c2.print();
    cout << endl;

    cout << "c3 = ";
    c3.print();
    cout << endl;

    // 测试加法
    Complex sum = c1.add(c2);
    cout << "c1 + c2 = ";
    sum.print();
    cout << endl;

    // 测试减法
    Complex difference = c1.subtract(c2);
    cout << "c1 - c2 = ";
    difference.print();
    cout << endl;

    return 0;
}