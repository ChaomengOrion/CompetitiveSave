#include <bits/stdc++.h>

using namespace std;

class Time {
private:
    int hour;    // 0-23 (24小时制)
    int minute;  // 0-59
    int second;  // 0-59

public:
    Time(int hr = 0, int min = 0, int sec = 0) {
        setTime(hr, min, sec);
    }

    // 设置时间值
    void setTime(int hr, int min, int sec) {
        hour = (hr >= 0 && hr < 24) ? hr : 0;
        minute = (min >= 0 && min < 60) ? min : 0;
        second = (sec >= 0 && sec < 60) ? sec : 0;
    }

    // 获取时间值
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }

    // 按标准格式打印时间，这里我设置格式为（HH:MM:SS AM/PM）
    string toStandardString() const {
        string amPm = (hour < 12) ? " AM" : " PM";
        int standardHour = (hour == 0 || hour == 12) ? 12 : hour % 12;
        
        return (to_string(standardHour) + ":" + 
                (minute < 10 ? "0" : "") + to_string(minute) + ":" + 
                (second < 10 ? "0" : "") + to_string(second) + amPm);
    }

    // tick函数：将时间增加一秒
    void tick() {
        second++;
        
        if (second == 60) {  // 秒数到达60，进位到分钟
            second = 0;
            minute++;
            
            if (minute == 60) {  // 分钟到达60，进位到小时
                minute = 0;
                hour++;
                
                if (hour == 24) {  // 小时到达24，重置为0（新的一天）
                    hour = 0;
                }
            }
        }
    }
};

int main() {
    // 增加分
    Time t1(10, 59, 59);  // 10:59:59 AM
    
    cout << "Test Case 1: Incrementing into the next minute" << endl;
    cout << "Initial time: " << t1.toStandardString() << endl;
    t1.tick();
    cout << "After tick: " << t1.toStandardString() << endl;
    cout << endl;
    
    // 增加时
    Time t2(11, 59, 59);  // 11:59:59 AM
    
    cout << "Test Case 2: Incrementing into the next hour" << endl;
    cout << "Initial time: " << t2.toStandardString() << endl;
    t2.tick();
    cout << "After tick: " << t2.toStandardString() << endl;
    cout << endl;
    
    // 新的一天
    Time t3(23, 59, 59);  // 11:59:59 PM
    
    cout << "Test Case 3: Incrementing into the next day" << endl;
    cout << "Initial time: " << t3.toStandardString() << endl;
    t3.tick();
    cout << "After tick: " << t3.toStandardString() << endl;
    cout << endl;
    
    Time t4(23, 59, 55);  // 11:59:55 PM
    
    cout << "Test Case 4: Continuous ticking across midnight" << endl;
    cout << "Initial time: " << t4.toStandardString() << endl;
    
    // 增加10秒
    for (int i = 1; i <= 10; ++i) {
        t4.tick();
        cout << "After tick " << i << ": " << t4.toStandardString() << endl;
    }
    
    return 0;
}