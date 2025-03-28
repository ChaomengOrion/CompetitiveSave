#include <bits/stdc++.h>

using namespace std;

class DateAndTime {
private:
    // 日期部分
    int month; // 1-12
    int day; // 1-31 根据月份
    int year; // 任何年份

    // 时间部分
    int hour; // 0-23 (24小时制)
    int minute; // 0-59
    int second; // 0-59

    // 检查年份是否为闰年
    bool isLeapYear(int y) const { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }

    // 获取指定月份的天数
    int daysInMonth(int m, int y) const {
        static const array<int, 13> daysPerMonth = {
            0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (m == 2 && isLeapYear(y)) {
            return 29;
        }

        return daysPerMonth[m];
    }

public:
    // 构造函数
    DateAndTime(int mm = 1, int dd = 1, int yy = 2000, int hr = 0, int min = 0, int sec = 0) {
        setDate(mm, dd, yy);
        setTime(hr, min, sec);
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

    // 设置时间值
    void setTime(int hr, int min, int sec) {
        hour = (hr >= 0 && hr < 24) ? hr : 0;
        minute = (min >= 0 && min < 60) ? min : 0;
        second = (sec >= 0 && sec < 60) ? sec : 0;
    }

    // tick函数：将时间增加一秒，如果需要也增加日期
    void tick() {
        second++;

        if (second == 60) {
            second = 0;
            minute++;

            if (minute == 60) {
                minute = 0;
                hour++;

                if (hour == 24) {
                    hour = 0;
                    nextDay(); // 调用nextDay增加一天
                }
            }
        }
    }

    // 打印标准格式（MM/DD/YYYY HH:MM:SS AM/PM）
    string printStandard() const {
        string date_str = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

        string amPm = (hour < 12) ? " AM" : " PM";
        int standardHour = (hour == 0 || hour == 12) ? 12 : hour % 12;

        string time_str = (standardHour < 10 ? " " : "") + to_string(standardHour) + ":" +
                          (minute < 10 ? "0" : "") + to_string(minute) + ":" +
                          (second < 10 ? "0" : "") + to_string(second) + amPm;

        return date_str + " " + time_str;
    }

    // 打印通用格式（YYYY-MM-DD HH:MM:SS，24小时制）
    string printUniversal() const {
        string date_str = to_string(year) + "-" + (month < 10 ? "0" : "") + to_string(month) + "-" +
                          (day < 10 ? "0" : "") + to_string(day);

        string time_str = (hour < 10 ? "0" : "") + to_string(hour) + ":" +
                          (minute < 10 ? "0" : "") + to_string(minute) + ":" +
                          (second < 10 ? "0" : "") + to_string(second);

        return date_str + " " + time_str;
    }

    // 获取日期和时间分量
    inline int getMonth() const { return month; }
    inline int getDay() const { return day; }
    inline int getYear() const { return year; }
    inline int getHour() const { return hour; }
    inline int getMinute() const { return minute; }
    inline int getSecond() const { return second; }
};

int main() {
    // 测试1：基本日期时间设置
    DateAndTime dt1(5, 10, 2023, 14, 30, 45);
    cout << "Test Case 1: Basic DateAndTime\n";
    cout << "Standard format: " << dt1.printStandard() << endl;
    cout << "Universal format: " << dt1.printUniversal() << endl << endl;

    // 测试2：增加时间不跨天
    DateAndTime dt2(6, 15, 2023, 12, 30, 45);
    cout << "Test Case 2: Ticking within the same day\n";
    cout << "Before tick: " << dt2.printStandard() << endl;
    dt2.tick();
    cout << "After tick: " << dt2.printStandard() << endl << endl;

    // 测试3：增加时间跨天但不跨月
    DateAndTime dt3(6, 15, 2023, 23, 59, 59);
    cout << "Test Case 3: Ticking into the next day\n";
    cout << "Before tick: " << dt3.printStandard() << endl;
    dt3.tick();
    cout << "After tick: " << dt3.printStandard() << endl << endl;

    // 测试4：增加时间跨月但不跨年
    DateAndTime dt4(6, 30, 2023, 23, 59, 59);
    cout << "Test Case 4: Ticking into the next month\n";
    cout << "Before tick: " << dt4.printStandard() << endl;
    dt4.tick();
    cout << "After tick: " << dt4.printStandard() << endl << endl;

    // 测试5：增加时间跨年
    DateAndTime dt5(12, 31, 2023, 23, 59, 59);
    cout << "Test Case 5: Ticking into the next year\n";
    cout << "Before tick: " << dt5.printStandard() << endl;
    dt5.tick();
    cout << "After tick: " << dt5.printStandard() << endl << endl;

    // 测试6：闰年处理
    DateAndTime dt6(2, 28, 2024, 23, 59, 59); // 2024是闰年
    cout << "Test Case 6: Leap year handling\n";
    cout << "Before tick: " << dt6.printStandard() << endl;
    dt6.tick();
    cout << "After tick: " << dt6.printStandard() << endl << endl;

    // 测试7：连续调用tick，观察日期和时间的变化
    DateAndTime dt7(12, 31, 2023, 23, 59, 55);
    cout << "Test Case 7: Continuous ticking across day/year boundary\n";
    cout << "Initial: " << dt7.printStandard() << endl;

    // 连续增加10秒
    for (int i = 1; i <= 10; ++i) {
        dt7.tick();
        cout << "After tick " << i << ": " << dt7.printStandard() << endl;
    }

    return 0;
}