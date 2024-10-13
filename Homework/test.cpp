#include <iostream>
using namespace std;

int main()
{
    int code = 10;
    cout << "Enter your paycode" << endl;
    cin >> code;
    switch (code) {
    case 1: {
        double manager = 0.0;
        cout << "您每周的工资是多少" << endl;
        cin >> manager;
        cout << "您每周的工资为:$" << manager;
    } break;

    case 2: {
        double hourly = 0.0;
        double hour = 0.0;
        cout << "请输入你每小时的固定工资" << endl;
        cin >> hourly;
        cout << "请输入你本周的工作时间" << endl;
        cin >> hour;
        if (hour <= 40) {
            cout << "你的工资为" << hour * hourly << endl;
        } else
            cout << "你的工资为:$" << 40 * hourly + 1.5 * hourly * (hour - 40);
    } break;

    case 3: {
        double sale = 0;
        cout << "请输入你本周的营销额" << endl;
        cin >> sale;
        cout << "你本周的工资为：" << 250 + 0.057 * sale << endl;
    } break;

    case 4: {
        int price = 0;
        int mount = 0;
        cout << "请输入产品单价" << endl;
        cin >> price;
        cout << "请输入生产件数" << endl;
        cin >> mount;
        cout << "您本周的工资为：" << price * mount << endl;
    } break;

    default: cout << "Your code is wrong" << endl;
    }
    system("pause");
    return 0;
}