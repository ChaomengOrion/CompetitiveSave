#include <iostream>
#include <vector>

bool is_leap_year(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return true;
    }
    return false;
}

std::vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

std::string get_weekday(int wday) {
    static const char* weekdays[] = {"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};
    return weekdays[wday];
}

void calculate_date(int year, int month, int day, int wday, int n) {
    day += n;
    while (true) {
        int days_this_month = days_in_month[month - 1];
        if (month == 2 && is_leap_year(year)) {
            days_this_month = 29;
        }
        if (day <= days_this_month) {
            break;
        }
        day -= days_this_month;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    wday = (wday + n) % 7;
    std::cout << "日期: " << year << "年" << month << "月" << day << "日" << get_weekday(wday) << std::endl;
}

int main() {
    int n;
    int year = 2024;
    int month = 10;
    int day = 24;
    int wday = 4; // 2024年10月24日是星期四

    while (std::cin >> n) {
        calculate_date(year, month, day, wday, n);
    }

    return 0;
}