#include <iostream>
#include <iomanip>

class SavingsAccount {
private:
    double savingsBalance; // 储蓄余额
    static double annualInterestRate; // 年利率（所有储户共享）

public:
    // 构造函数
    SavingsAccount(double balance = 0.0) : savingsBalance(balance) {}

    // 计算月利息并更新余额
    void calculateMonthlyInterest() {
        // 月利息 = 余额 * (年利率 / 12)
        double monthlyInterest = savingsBalance * (annualInterestRate / 12);
        savingsBalance += monthlyInterest;
    }

    // 获取当前余额
    double getBalance() const {
        return savingsBalance;
    }

    // 静态成员函数：修改年利率
    static void modifyInterestRate(double newRate) {
        // 检查利率是否有效（非负数）
        if (newRate >= 0.0) {
            annualInterestRate = newRate;
        } else {
            std::cout << "Error: Interest rate cannot be negative." << std::endl;
        }
    }
};

// 初始化静态成员变量
double SavingsAccount::annualInterestRate = 0.0;

int main() {
    // 创建两个SavingsAccount对象
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    // 设置输出格式为固定小数点，保留2位小数
    std::cout << std::fixed << std::setprecision(2);

    // 设置年利率为3%
    SavingsAccount::modifyInterestRate(0.03);
    
    // 输出初始余额
    std::cout << "Initial balances:" << std::endl;
    std::cout << "Saver1: $" << saver1.getBalance() << std::endl;
    std::cout << "Saver2: $" << saver2.getBalance() << std::endl;
    std::cout << std::endl;

    // 计算月利息并打印新余额（年利率3%）
    std::cout << "After first month (3% annual interest rate):" << std::endl;
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    std::cout << "Saver1: $" << saver1.getBalance() << std::endl;
    std::cout << "Saver2: $" << saver2.getBalance() << std::endl;
    std::cout << std::endl;

    // 将年利率修改为4%
    SavingsAccount::modifyInterestRate(0.04);

    // 计算下一个月的利息并打印新余额（年利率4%）
    std::cout << "After second month (4% annual interest rate):" << std::endl;
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    std::cout << "Saver1: $" << saver1.getBalance() << std::endl;
    std::cout << "Saver2: $" << saver2.getBalance() << std::endl;

    return 0;
}