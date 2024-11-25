#include <iostream>
#include <iomanip>

using namespace std;

const int SALESPEOPLE = 4;
const int PRODUCTS = 5;

int main() {
    double sales[PRODUCTS][SALESPEOPLE] = {0.0}; // 初始化二维数组，存储销售数据
    int salesperson, product;
    double value;

    // 读取销售数据
    cout << "Enter sales data (salesperson product value). Enter -1 to end:" << endl;
    while (true) {
        cin >> salesperson;
        if (salesperson == -1) break;
        cin >> product >> value;
        if (salesperson >= 1 && salesperson <= SALESPEOPLE && product >= 1 && product <= PRODUCTS) {
            sales[product - 1][salesperson - 1] += value;
        } else {
            cout << "Invalid input. Please enter valid salesperson and product numbers." << endl;
        }
    }

    // 打印表头
    cout << setw(10) << "Product";
    for (int i = 1; i <= SALESPEOPLE; ++i) {
        cout << setw(10) << "Salesperson " << i;
    }
    cout << setw(10) << "Total" << endl;

    // 打印销售数据和每个产品的总销售额
    for (int i = 0; i < PRODUCTS; ++i) {
        double productTotal = 0.0;
        cout << setw(10) << "Product " << i + 1;
        for (int j = 0; j < SALESPEOPLE; ++j) {
            cout << setw(10) << sales[i][j];
            productTotal += sales[i][j];
        }
        cout << setw(10) << productTotal << endl;
    }

    // 打印每个销售员的总销售额
    cout << setw(10) << "Total";
    for (int j = 0; j < SALESPEOPLE; ++j) {
        double salespersonTotal = 0.0;
        for (int i = 0; i < PRODUCTS; ++i) {
            salespersonTotal += sales[i][j];
        }
        cout << setw(10) << salespersonTotal;
    }
    cout << endl;

    return 0;
}