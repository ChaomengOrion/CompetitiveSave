#include <bits/stdc++.h>

class BankAccount {
private:
    std::string customerName;
    double balance;

public:
    // 构造函数 [必须提供客户姓名，余额可选（默认为0）]
    BankAccount(const std::string& name, double initialBalance = 0.0) {
        if (name.empty()) {
            throw std::runtime_error("客户姓名不能为空");
        }
        if (initialBalance < 0) {
            throw std::runtime_error("初始余额不能为负数");
        }
        customerName = name;
        balance = initialBalance;
    }

    // 获取客户姓名
    const std::string& getName() const { return customerName; }

    // 获取账户余额
    double getBalance() const { return balance; }

    // 存款
    void deposit(double amount) {
        if (amount <= 0) {
            throw std::runtime_error("存款金额必须为正数");
        }
        balance += amount;
    }

    // 取款
    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::runtime_error("取款金额必须为正数");
        }
        if (amount > balance) {
            throw std::runtime_error("余额不足");
        }
        balance -= amount;
    }

    // 显示账户信息
    void displayAccount() const {
        std::cout << "客户: " << customerName << std::endl;
        std::cout << "余额: " << balance << std::endl;
    }
};

void test1() {
    // 测试创建账户
    std::cout << "创建账户测试:" << std::endl;
    BankAccount account1("张三", 1000);
    account1.displayAccount();

    std::cout << "\n存款测试:" << std::endl;
    account1.deposit(500);
    std::cout << "存款500后 - ";
    std::cout << "余额: " << account1.getBalance() << std::endl;

    std::cout << "\n取款测试:" << std::endl;
    account1.withdraw(200);
    std::cout << "取款200后 - ";
    std::cout << "余额: " << account1.getBalance() << std::endl;

    std::cout << "\n创建多个账户:" << std::endl;
    BankAccount account2("李四", 2000);
    account2.displayAccount();
}

void test2() {
    BankAccount invalidAccount("", 100); // 空名称

    BankAccount negativeBalance("王五", -100); // 负余额

    BankAccount account1("张三", 1000);
    account1.withdraw(5000); // 取款超过余额
}

int main() {
    try {
        test1(); //? 正常测试
        test2(); //? 异常测试
    } catch (const std::exception& e) {
        std::cout << "发生异常: " << e.what() << std::endl;
    }
    return 0;
}