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

class Bank {
    std::unordered_map<std::string, BankAccount> account_map;

public:
    bool addAccount(const std::string& name, BankAccount account) {
        if (account_map.contains(name)) {
            return false; // 已经存在这个账户了，我们不允许继续添加
        }
        account_map.emplace(name, account);
        return true;
    }

    // 显示所有账户
    void printAccounts() {
        if (account_map.empty()) {
            std::cout << "银行没有任何账户" << std::endl;
            return;
        }

        std::cout << "银行账户列表:" << std::endl;
        for (auto&& [k, v] : account_map) {
            std::cout << "-------------------" << std::endl;
            v.displayAccount();
        }
    }

    // 为特定账户存款
    bool deposit(const std::string& name, double amount) {
        if (!account_map.contains(name)) {
            return false;
        }

        try {
            account_map.at(name).deposit(amount);
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }

    // 从特定账户取款
    bool withdraw(const std::string& name, double amount) {
        if (!account_map.contains(name)) {
            return false;
        }

        try {
            account_map.at(name).withdraw(amount);
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }

    // 为所有账户添加利息
    void addInterest(int percentage) {
        if (percentage <= 0) {
            throw std::runtime_error("利率必须为正数");
        }

        double rate = percentage / 100.0;
        for (auto& [name, account] : account_map) {
            double interest = account.getBalance() * rate;
            account.deposit(interest);
        }
    }

    // 账户间转账
    bool transfer(const std::string& fromName, const std::string& toName, double amount) {
        if (fromName == toName) {
            return false; // 不能自己转给自己
        }

        if (!account_map.contains(fromName) || !account_map.contains(toName)) {
            return false; // 账户不存在
        }

        if (amount <= 0) {
            return false; // 转账金额必须为正数
        }

        try {
            // 先检查转出账户是否有足够余额
            auto& fromAccount = account_map.at(fromName);
            if (fromAccount.getBalance() < amount) {
                return false; // 余额不足
            }

            // 执行转账操作
            fromAccount.withdraw(amount);
            account_map.at(toName).deposit(amount);
            return true;
        } catch (const std::exception&) {
            return false;
        }
    }
};

void test1() {
    std::cout << "===== 开始正常测试 =====" << std::endl;
    
    Bank bank;
    
    // 测试添加账户
    std::cout << "测试添加账户:" << std::endl;
    bank.addAccount("张三", BankAccount("张三", 1000));
    bank.addAccount("李四", BankAccount("李四", 2000));
    bank.addAccount("王五", BankAccount("王五", 3000));
    
    // 显示所有账户
    std::cout << "\n显示所有账户:" << std::endl;
    bank.printAccounts();
    
    // 测试存款
    std::cout << "\n测试存款:" << std::endl;
    if (bank.deposit("张三", 500)) {
        std::cout << "张三存款500成功" << std::endl;
    }
    
    // 测试取款
    std::cout << "\n测试取款:" << std::endl;
    if (bank.withdraw("李四", 200)) {
        std::cout << "李四取款200成功" << std::endl;
    }
    
    // 测试利息添加
    std::cout << "\n测试添加利息:" << std::endl;
    bank.addInterest(5);  // 添加5%的利息
    std::cout << "为所有账户添加5%的利息成功" << std::endl;
    
    // 测试转账
    std::cout << "\n测试转账:" << std::endl;
    if (bank.transfer("王五", "张三", 500)) {
        std::cout << "王五转账500给张三成功" << std::endl;
    }
    
    // 显示更新后的账户信息
    std::cout << "\n更新后的账户信息:" << std::endl;
    bank.printAccounts();
    
    std::cout << "===== 正常测试结束 =====" << std::endl;
}

void test2() {
    std::cout << "\n===== 开始异常测试 =====" << std::endl;
    
    Bank bank;
    
    // 添加初始账户
    bank.addAccount("张三", BankAccount("张三", 1000));
    bank.addAccount("李四", BankAccount("李四", 2000));
    
    // 测试重复添加账户
    std::cout << "测试重复添加账户:" << std::endl;
    if (!bank.addAccount("张三", BankAccount("张三", 500))) {
        std::cout << "重复添加张三账户失败（预期结果）" << std::endl;
    }
    
    // 测试负数存款
    std::cout << "\n测试负数存款:" << std::endl;
    if (!bank.deposit("张三", -100)) {
        std::cout << "张三存款-100失败（预期结果）" << std::endl;
    }
    
    // 测试超额取款
    std::cout << "\n测试超额取款:" << std::endl;
    if (!bank.withdraw("张三", 2000)) {
        std::cout << "张三取款2000失败（余额不足，预期结果）" << std::endl;
    }
    
    // 测试不存在账户操作
    std::cout << "\n测试不存在账户操作:" << std::endl;
    if (!bank.deposit("不存在", 500)) {
        std::cout << "不存在的账户存款失败（预期结果）" << std::endl;
    }
    
    if (!bank.withdraw("不存在", 500)) {
        std::cout << "不存在的账户取款失败（预期结果）" << std::endl;
    }
    
    // 测试无效转账
    std::cout << "\n测试无效转账:" << std::endl;
    if (!bank.transfer("张三", "张三", 100)) {
        std::cout << "自己转给自己失败（预期结果）" << std::endl;
    }
    
    if (!bank.transfer("张三", "不存在", 100)) {
        std::cout << "转账给不存在账户失败（预期结果）" << std::endl;
    }
    
    if (!bank.transfer("张三", "李四", -100)) {
        std::cout << "负数转账失败（预期结果）" << std::endl;
    }
    
    if (!bank.transfer("张三", "李四", 2000)) {
        std::cout << "超额转账失败（余额不足，预期结果）" << std::endl;
    }
    
    // 测试最终账户状态
    std::cout << "\n最终账户状态:" << std::endl;
    bank.printAccounts();
    
    std::cout << "===== 异常测试结束 =====" << std::endl;
}

int main() {
    try {
        test1(); // 正常测试
        test2(); // 异常测试
    } catch (const std::exception& e) {
        std::cout << "发生异常: " << e.what() << std::endl;
    }
    return 0;
}
