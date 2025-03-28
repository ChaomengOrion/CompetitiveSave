#include <bits/stdc++.h>

using namespace std;

// Rational类定义
class Rational {
private:
    int numerator;    // 分子
    int denominator;  // 分母

    // 辅助函数：将分数化简为最简形式
    void reduce() {
        if (denominator < 0) {  // 如果分母为负，将符号转移到分子
            numerator = -numerator;
            denominator = -denominator;
        }

        int gcd_value = std::gcd(abs(numerator), denominator);
        numerator /= gcd_value;
        denominator /= gcd_value;
    }

public:
    // 构造函数，带默认参数
    Rational(int num = 0, int denom = 1) {
        if (denom == 0) {
            cout << "Error: Denominator cannot be zero. Setting to 1." << endl;
            numerator = num;
            denominator = 1;
        } else {
            numerator = num;
            denominator = denom;
        }
        reduce();  // 将分数化简为最简形式
    }

    // 加法运算
    Rational add(const Rational& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_denom = denominator * other.denominator;
        return Rational(new_num, new_denom);
    }

    // 减法运算
    Rational subtract(const Rational& other) const {
        int new_num = numerator * other.denominator - other.numerator * denominator;
        int new_denom = denominator * other.denominator;
        return Rational(new_num, new_denom);
    }

    // 乘法运算
    Rational multiply(const Rational& other) const {
        int new_num = numerator * other.numerator;
        int new_denom = denominator * other.denominator;
        return Rational(new_num, new_denom);
    }

    // 除法运算
    Rational divide(const Rational& other) const {
        if (other.numerator == 0) {
            cout << "Error: Division by zero. Returning 0/1." << endl;
            return Rational();
        }
        int new_num = numerator * other.denominator;
        int new_denom = denominator * other.numerator;
        return Rational(new_num, new_denom);
    }

    // 打印分数形式
    void printRational() const {
        cout << numerator << "/" << denominator;
    }

    // 打印浮点数形式
    void printFloat() const {
        cout << static_cast<double>(numerator) / denominator;
    }
};

int main() {
    Rational r1(2, 4);    // 会被简化为 1/2
    Rational r2(3, 6);    // 会被简化为 1/2
    Rational r3(7, 3);
    Rational r4;          // 使用默认构造函数，值为 0/1

    cout << "r1 = ";
    r1.printRational();
    cout << " = ";
    r1.printFloat();
    cout << endl;

    cout << "r2 = ";
    r2.printRational();
    cout << " = ";
    r2.printFloat();
    cout << endl;

    cout << "r3 = ";
    r3.printRational();
    cout << " = ";
    r3.printFloat();
    cout << endl;

    cout << "r4 = ";
    r4.printRational();
    cout << " = ";
    r4.printFloat();
    cout << endl;

    // 加
    Rational sum = r1.add(r3);
    cout << "r1 + r3 = ";
    sum.printRational();
    cout << " = ";
    sum.printFloat();
    cout << endl;

    // 减
    Rational difference = r1.subtract(r3);
    cout << "r1 - r3 = ";
    difference.printRational();
    cout << " = ";
    difference.printFloat();
    cout << endl;

    // 乘
    Rational product = r1.multiply(r3);
    cout << "r1 * r3 = ";
    product.printRational();
    cout << " = ";
    product.printFloat();
    cout << endl;

    // 除
    Rational quotient = r1.divide(r3);
    cout << "r1 / r3 = ";
    quotient.printRational();
    cout << " = ";
    quotient.printFloat();
    cout << endl;

    // 测试分母为零的情况
    Rational invalid(5, 0);  // 应该显示错误消息并设置为 5/1

    // 测试除以零的情况
    Rational zero;
    Rational divideByZero = r1.divide(zero);  // 应该显示错误消息并返回 0/1

    return 0;
}