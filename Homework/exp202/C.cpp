#include <iostream>
#include <string>
#include <vector>
#include <memory>

// 原料基类
class Ingredient {
protected:
    std::string name;
    double amount; // 单位可以是毫升或克
    std::string unit;

public:
    Ingredient(std::string name, double amount, std::string unit)
        : name(std::move(name)), amount(amount), unit(std::move(unit)) {}
    
    virtual ~Ingredient() = default;
    
    std::string getName() const { return name; }
    double getAmount() const { return amount; }
    std::string getUnit() const { return unit; }
    
    virtual void display() const {
        std::cout << amount << " " << unit << " " << name;
    }
};

// 具体原料类 - 浓缩咖啡
class Espresso : public Ingredient {
public:
    Espresso(double amount = 30) : Ingredient("浓缩咖啡", amount, "ml") {}
};

// 具体原料类 - 牛奶
class Milk : public Ingredient {
public:
    Milk(double amount = 100) : Ingredient("牛奶", amount, "ml") {}
};

// 具体原料类 - 奶泡
class MilkFoam : public Ingredient {
public:
    MilkFoam(double amount = 30) : Ingredient("奶泡", amount, "ml") {}
};

// 具体原料类 - 水
class Water : public Ingredient {
public:
    Water(double amount = 100) : Ingredient("水", amount, "ml") {}
};

// 具体原料类 - 巧克力
class Chocolate : public Ingredient {
public:
    Chocolate(double amount = 20) : Ingredient("巧克力酱", amount, "g") {}
};

// 具体原料类 - 肉桂
class Cinnamon : public Ingredient {
public:
    Cinnamon(double amount = 5) : Ingredient("肉桂", amount, "g") {}
};

// 基于浓缩咖啡的饮品基类
class EspressoBased {
protected:
    std::string name;
    std::vector<std::unique_ptr<Ingredient>> ingredients;

public:
    EspressoBased(std::string name) : name(std::move(name)) {
        // 所有基于浓缩咖啡的饮品都包含浓缩咖啡
        ingredients.push_back(std::make_unique<Espresso>());
    }
    
    virtual ~EspressoBased() = default;
    
    std::string getName() const { return name; }
    
    void addIngredient(std::unique_ptr<Ingredient> ingredient) {
        ingredients.push_back(std::move(ingredient));
    }
    
    virtual void prepare() const {
        std::cout << "准备 " << name << ":" << std::endl;
        for (const auto& ingredient : ingredients) {
            std::cout << "- 添加 ";
            ingredient->display();
            std::cout << std::endl;
        }
        std::cout << name << " 准备完成!" << std::endl;
    }
};

// 具体咖啡类 - 拿铁
class Latte : public EspressoBased {
public:
    Latte() : EspressoBased("拿铁") {
        addIngredient(std::make_unique<Milk>(150));
        addIngredient(std::make_unique<MilkFoam>(30));
    }
};

// 具体咖啡类 - 卡布奇诺
class Cappuccino : public EspressoBased {
public:
    Cappuccino() : EspressoBased("卡布奇诺") {
        addIngredient(std::make_unique<Milk>(100));
        addIngredient(std::make_unique<MilkFoam>(60));
    }
};

// 具体咖啡类 - 摩卡
class Mocha : public EspressoBased {
public:
    Mocha() : EspressoBased("摩卡") {
        addIngredient(std::make_unique<Milk>(100));
        addIngredient(std::make_unique<Chocolate>());
        addIngredient(std::make_unique<MilkFoam>(30));
    }
};

// 具体咖啡类 - 美式咖啡
class Americano : public EspressoBased {
public:
    Americano() : EspressoBased("美式咖啡") {
        addIngredient(std::make_unique<Water>());
    }
};

// 咖啡工厂类
class CoffeeShop {
public:
    std::unique_ptr<EspressoBased> orderCoffee(const std::string& type) {
        std::cout << "收到订单：" << type << std::endl;
        
        if (type == "拿铁") {
            return std::make_unique<Latte>();
        } else if (type == "卡布奇诺") {
            return std::make_unique<Cappuccino>();
        } else if (type == "摩卡") {
            return std::make_unique<Mocha>();
        } else if (type == "美式咖啡") {
            return std::make_unique<Americano>();
        } else {
            std::cout << "抱歉，我们不提供这种咖啡。" << std::endl;
            return nullptr;
        }
    }
};

int main() {
    CoffeeShop shop;
    
    std::vector<std::string> orders = {"拿铁", "卡布奇诺", "摩卡", "美式咖啡", "balalala"};
    
    for (const auto& order : orders) {
        auto coffee = shop.orderCoffee(order);
        if (coffee) {
            coffee->prepare();
            std::cout << std::endl;
        }
    }
    
    // 自定义咖啡示例
    std::cout << "创建自定义咖啡:" << std::endl;
    auto customCoffee = std::make_unique<EspressoBased>("自定义特调");
    customCoffee->addIngredient(std::make_unique<Milk>(50));
    customCoffee->addIngredient(std::make_unique<Chocolate>(15));
    customCoffee->addIngredient(std::make_unique<Cinnamon>());
    customCoffee->prepare();
    
    return 0;
}