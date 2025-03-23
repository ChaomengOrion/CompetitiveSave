#include <bits/stdc++.h>

class Polynomial {
private:
    // 多项式的一项，包含系数和指数
    struct Term {
        double coefficient;  // 系数
        int exponent;        // 指数

        // 构造函数
        Term(double coeff = 0.0, int exp = 0) : coefficient(coeff), exponent(exp) {}

        // 比较函数，用于排序（指数降序）
        bool operator<(const Term& other) const {
            return exponent > other.exponent;  // 降序排列
        }

        // 相等比较，用于查找相同指数的项
        bool operator==(const Term& other) const {
            return exponent == other.exponent;
        }
    };

    std::vector<Term> terms;  // 多项式的各项

    // 整理多项式：合并同类项并移除系数为0的项
    void normalize() {
        // 按指数降序排序
        std::sort(terms.begin(), terms.end());

        // 合并同类项
        std::vector<Term> result;
        for (size_t i = 0; i < terms.size(); ++i) {
            if (terms[i].coefficient != 0) {
                // 检查是否存在相同指数的项
                if (!result.empty() && result.back().exponent == terms[i].exponent) {
                    result.back().coefficient += terms[i].coefficient;
                    // 如果合并后系数为0，则移除该项
                    if (result.back().coefficient == 0) {
                        result.pop_back();
                    }
                } else {
                    result.push_back(terms[i]);
                }
            }
        }

        terms = result;
    }

public:
    // 默认构造函数
    Polynomial() = default;

    // 通过系数和指数构造多项式
    Polynomial(const std::vector<double>& coefficients, const std::vector<int>& exponents) {
        if (coefficients.size() != exponents.size()) {
            throw std::invalid_argument("系数和指数的数量必须相同");
        }

        for (size_t i = 0; i < coefficients.size(); ++i) {
            if (coefficients[i] != 0) { // 只添加非零系数的项
                terms.emplace_back(coefficients[i], exponents[i]);
            }
        }
        normalize();
    }

    // 拷贝构造函数
    Polynomial(const Polynomial& other) = default;

    // 析构函数
    ~Polynomial() = default;

    // 设置多项式
    void setPolynomial(const std::vector<double>& coefficients, const std::vector<int>& exponents) {
        terms.clear();
        if (coefficients.size() != exponents.size()) {
            throw std::invalid_argument("系数和指数的数量必须相同");
        }

        for (size_t i = 0; i < coefficients.size(); ++i) {
            if (coefficients[i] != 0) { // 只添加非零系数的项
                terms.emplace_back(coefficients[i], exponents[i]);
            }
        }
        normalize();
    }

    // 添加一项
    void addTerm(double coefficient, int exponent) {
        if (coefficient != 0) {
            terms.emplace_back(coefficient, exponent);
            normalize();
        }
    }

    // 获取多项式的项数
    size_t getNumberOfTerms() const noexcept {
        return terms.size();
    }

    // 获取指定位置的项
    bool getTerm(size_t index, double coefficient, int exponent) const {
        if (index < terms.size()) {
            coefficient = terms[index].coefficient;
            exponent = terms[index].exponent;
            return true;
        }
        return false;
    }

    // 重载加法运算符 (+)
    Polynomial operator+(const Polynomial& other) const {
        Polynomial result = *this;
        result += other;
        return result;
    }

    // 重载减法运算符 (-)
    Polynomial operator-(const Polynomial& other) const {
        Polynomial result = *this;
        result -= other;
        return result;
    }

    // 重载赋值运算符 (=)
    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) { // 指针判断引用是否一样
            terms = other.terms;
        }
        return *this;
    }

    // 重载乘法运算符 (*)
    Polynomial operator*(const Polynomial& other) const {
        Polynomial result;
        for (const Term& t1 : terms) {
            for (const Term& t2 : other.terms) {
                result.addTerm(t1.coefficient * t2.coefficient, t1.exponent + t2.exponent);
            }
        }
        return result;
    }

    // 重载加法赋值运算符 (+=)
    Polynomial& operator+=(const Polynomial& other) {
        for (const Term& term : other.terms) {
            terms.push_back(term);
        }
        normalize();
        return *this;
    }

    // 重载减法赋值运算符 (-=)
    Polynomial& operator-=(const Polynomial& other) {
        for (const Term& term : other.terms) {
            terms.emplace_back(-term.coefficient, term.exponent);
        }
        normalize();
        return *this;
    }

    // 重载乘法赋值运算符 (*=)
    Polynomial& operator*=(const Polynomial& other) {
        *this = *this * other;
        return *this;
    }

    // 重载流插入运算符 (<<)
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
        if (poly.terms.empty()) {
            os << "0";
            return os;
        }

        bool isFirst = true;
        for (const Term& term : poly.terms) {
            if (term.coefficient == 0) continue;

            if (!isFirst) {
                if (term.coefficient > 0) {
                    os << " + ";
                } else {
                    os << " - ";
                }
            } else if (term.coefficient < 0) {
                os << "-";
            }

            double absCoeff = std::abs(term.coefficient);
            if (absCoeff != 1 || term.exponent == 0) {
                os << absCoeff;
            }

            if (term.exponent > 0) {
                os << "x";
                if (term.exponent > 1) {
                    os << "^" << term.exponent;
                }
            }

            isFirst = false;
        }
        return os;
    }

    // 重载流提取运算符 (>>)
    friend std::istream& operator>>(std::istream& is, Polynomial& poly) {
        // 先清空原有的多项式
        poly.terms.clear();

        // 临时变量用于读取
        double coefficient;
        int exponent;
        
        std::string input;
        std::getline(is, input); // 先缓存这一行
        std::stringstream ss(input);
        
        // 读取格式为 "coeff exp coeff exp ..."
        while (ss >> coefficient >> exponent) {
            poly.addTerm(coefficient, exponent);
        }
        
        return is;
    }
};

int main() {
    // 创建多项式1：3x^2 + 5x + 2
    std::vector<double> coeffs1 = {3, 5, 2};
    std::vector<int> exps1 = {2, 1, 0};
    Polynomial p1(coeffs1, exps1);
    
    // 创建多项式2：x^3 - 2x
    std::vector<double> coeffs2 = {1, -2};
    std::vector<int> exps2 = {3, 1};
    Polynomial p2(coeffs2, exps2);
    
    // 显示多项式
    std::cout << "多项式1: " << p1 << std::endl;
    std::cout << "多项式2: " << p2 << std::endl;
    
    // 测试加法
    Polynomial p3 = p1 + p2;
    std::cout << "p1 + p2 = " << p3 << std::endl;
    
    // 测试减法
    Polynomial p4 = p1 - p2;
    std::cout << "p1 - p2 = " << p4 << std::endl;
    
    // 测试乘法
    Polynomial p5 = p1 * p2;
    std::cout << "p1 * p2 = " << p5 << std::endl;
    
    // 测试赋值
    Polynomial p6;
    p6 = p1;
    std::cout << "p6 = p1: " << p6 << std::endl;
    
    // 测试加法赋值
    p6 += p2;
    std::cout << "p6 += p2: " << p6 << std::endl;
    
    // 测试减法赋值
    p6 -= p2;
    std::cout << "p6 -= p2: " << p6 << std::endl;
    
    // 测试乘法赋值
    p6 *= p2;
    std::cout << "p6 *= p2: " << p6 << std::endl;
    
    // 测试输入
    Polynomial p7;
    std::cout << "输入多项式的系数和指数对 (例如: 3 2 5 1 7 0 表示 3x^2 + 5x + 7，两个一对，回车结束): ";
    std::cin >> p7;
    std::cout << "输入的多项式: " << p7 << std::endl;
    
    return 0;
}