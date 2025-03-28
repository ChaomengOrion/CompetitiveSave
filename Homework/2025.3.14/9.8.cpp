#include <bits/stdc++.h>

using namespace std;

class Date {
private:
    int month; // 1-12
    int day;   // 1-31 根据月份
    int year;  // 任何年份
    
    // 检查年份是否为闰年
    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
    
    // 获取指定月份的天数
    int daysInMonth(int m, int y) const {
        static const array<int, 13> daysPerMonth = 
            {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            
        if (m == 2 && isLeapYear(y)) {
            return 29;
        }
        
        return daysPerMonth[m];
    }

public:
    // 构造函数：执行错误检查
    Date(int mm = 1, int dd = 1, int yy = 2000) {
        setDate(mm, dd, yy);
    }
    
    // 设置日期，执行错误检查
    void setDate(int mm, int dd, int yy) {
        // 检查月份是否有效
        if (mm >= 1 && mm <= 12) {
            month = mm;
        } else {
            month = 1; // 默认为1月
            cout << "Invalid month (" << mm << ") set to 1.\n";
        }
        
        year = yy; // 先设置年份，因为检查天数时需要判断闰年
        
        // 检查天数是否有效
        int maxDay = daysInMonth(month, year);
        if (dd >= 1 && dd <= maxDay) {
            day = dd;
        } else {
            day = 1; // 默认为1日
            cout << "Invalid day (" << dd << ") set to 1.\n";
        }
    }
    
    // 增加一天
    void nextDay() {
        // 检查是否需要进入下一个月
        if (day < daysInMonth(month, year)) {
            day++;
        } else {
            day = 1; // 重置为下个月的第一天
            
            // 检查是否需要进入下一年
            if (month == 12) {
                month = 1;
                year++;
            } else {
                month++;
            }
        }
    }
    
    // 打印日期（格式：MM/DD/YYYY）
    string toString() const {
        return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    }
    
    // 获取日期分量
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }
};

int main() {
    // 测试1：检查错误处理
    cout << "Test Case 1: Error checking in constructor\n";
    Date invalidDate(13, 32, 2023); // 无效的月份和天数
    cout << "After correction: " << invalidDate.toString() << "\n\n";
    
    // 测试2：增加到下一个月
    cout << "Test Case 2: Incrementing into the next month\n";
    Date date1(1, 31, 2023); // 1月31日
    cout << "Initial date: " << date1.toString() << "\n";
    date1.nextDay();
    cout << "After nextDay: " << date1.toString() << "\n\n";
    
    // 测试3：增加到下一年
    cout << "Test Case 3: Incrementing into the next year\n";
    Date date2(12, 31, 2023); // 12月31日
    cout << "Initial date: " << date2.toString() << "\n";
    date2.nextDay();
    cout << "After nextDay: " << date2.toString() << "\n\n";
    
    // 测试4：闰年测试（2月28日到3月1日或2月29日）
    cout << "Test Case 4a: February in a non-leap year\n";
    Date date3(2, 28, 2023); // 2023年不是闰年
    cout << "Initial date: " << date3.toString() << "\n";
    date3.nextDay();
    cout << "After nextDay: " << date3.toString() << "\n\n";
    
    cout << "Test Case 4b: February in a leap year\n";
    Date date4(2, 28, 2024); // 2024年是闰年
    cout << "Initial date: " << date4.toString() << "\n";
    date4.nextDay();
    cout << "After nextDay: " << date4.toString() << "\n";
    date4.nextDay();
    cout << "After another nextDay: " << date4.toString() << "\n\n";
    
    // 测试5：连续调用nextDay
    cout << "Test Case 5: Continuous nextDay calls\n";
    Date date5(12, 29, 2023);
    cout << "Initial date: " << date5.toString() << "\n";
    
    // 连续增加5天
    for (int i = 1; i <= 5; ++i) {
        date5.nextDay();
        cout << "After nextDay " << i << ": " << date5.toString() << "\n";
    }
    
    return 0;
}