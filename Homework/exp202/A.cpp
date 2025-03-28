#include <bits/stdc++.h>

// 账户基类
class Account {
protected:
    double balance; // 账户余额

public:
    // 构造函数
    Account(double initialBalance) {
        if (initialBalance >= 0.0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            std::cout << "错误: 初始余额无效。已设为0.0。" << std::endl;
        }
    }

    // 存款
    void credit(double amount) {
        if (amount > 0.0) {
            balance += amount;
        }
    }

    // 取款
    bool debit(double amount) {
        if (amount > balance) {
            std::cout << "取款金额超过账户余额。" << std::endl;
            return false;
        } else {
            balance -= amount;
            return true;
        }
    }

    // 获取余额
    double getBalance() const {
        return balance;
    }
};

// 储蓄账户类
class SavingsAccount : public Account {
private:
    double interestRate; // 利率（百分比）

public:
    // 构造函数
    SavingsAccount(double initialBalance, double rate)
        : Account(initialBalance) {
        interestRate = (rate < 0.0) ? 0.0 : rate;
    }

    // 计算利息
    double calculateInterest() {
        double interest = balance * interestRate;
        return interest;
    }
};

// 支票账户类
class CheckingAccount : public Account {
private:
    double transactionFee; // 交易费用

public:
    // 构造函数
    CheckingAccount(double initialBalance, double fee)
        : Account(initialBalance) {
        transactionFee = (fee < 0.0) ? 0.0 : fee;
    }

    // 重定义存款方法
    void credit(double amount) {
        Account::credit(amount); // 调用基类方法
        balance -= transactionFee; // 扣除交易费用
        std::cout << "已扣除交易费用: " << transactionFee << std::endl;
    }

    // 重定义取款方法
    bool debit(double amount) {
        bool success = Account::debit(amount); // 调用基类方法
        if (success) {
            balance -= transactionFee; // 扣除交易费用
            std::cout << "已扣除交易费用: " << transactionFee << std::endl;
        }
        return success;
    }
};

int main() {
    // 设置输出格式
    std::cout << std::fixed << std::setprecision(2);

    // 测试基类Account
    std::cout << "\n===== 测试Account类 =====\n";
    Account account(1000.0);
    std::cout << "初始余额: " << account.getBalance() << std::endl;
    
    account.credit(500.0);
    std::cout << "存款500后余额: " << account.getBalance() << std::endl;
    
    account.debit(200.0);
    std::cout << "取款200后余额: " << account.getBalance() << std::endl;
    
    account.debit(2000.0); // 尝试取款超过余额
    std::cout << "尝试取款2000后余额: " << account.getBalance() << std::endl;

    // 测试SavingsAccount类
    std::cout << "\n===== 测试SavingsAccount类 =====\n";
    SavingsAccount savingsAccount(2000.0, 0.05); // 5%的利率
    std::cout << "初始余额: " << savingsAccount.getBalance() << std::endl;
    
    savingsAccount.credit(1000.0);
    std::cout << "存款1000后余额: " << savingsAccount.getBalance() << std::endl;
    
    double interest = savingsAccount.calculateInterest();
    std::cout << "计算的利息: " << interest << std::endl;
    
    savingsAccount.credit(interest); // 添加利息到账户
    std::cout << "添加利息后余额: " << savingsAccount.getBalance() << std::endl;

    // 测试CheckingAccount类
    std::cout << "\n===== 测试CheckingAccount类 =====\n";
    CheckingAccount checkingAccount(3000.0, 1.0); // 每次交易收费1.0
    std::cout << "初始余额: " << checkingAccount.getBalance() << std::endl;
    
    checkingAccount.credit(500.0);
    std::cout << "存款500后余额: " << checkingAccount.getBalance() << std::endl;
    
    checkingAccount.debit(200.0);
    std::cout << "取款200后余额: " << checkingAccount.getBalance() << std::endl;
    
    checkingAccount.debit(4000.0); // 尝试取款超过余额
    std::cout << "尝试取款4000后余额: " << checkingAccount.getBalance() << std::endl;

    return 0;
}