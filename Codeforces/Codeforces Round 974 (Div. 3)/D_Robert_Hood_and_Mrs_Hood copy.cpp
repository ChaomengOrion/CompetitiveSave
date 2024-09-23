#include <bits/stdc++.h>
#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size)                     \
    std::cerr << '[';                         \
    for (int i = 0; i < size; i++) {          \
        std::cerr << vec[i];                  \
        if (i != size - 1) std::cerr << ", "; \
    }                                         \
    std::cerr << ']' << std::endl;

struct Event {
    int time;
    int type; // 1 for start, -1 for end
};

void solve()
{
    int n, d, k; // 总天数、访问持续时间和工作数量
    std::cin >> n >> d >> k;
    std::vector<Event> events;

    for (int i = 0; i < k; i++) {
        int start, end;
        std::cin >> start >> end;
        events.push_back({start, 1});
        events.push_back({end + 1, -1});
    }

    // 按时间排序，如果时间相同，结束事件排在开始事件之前
    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        if (a.time == b.time) return a.type < b.type;
        return a.time < b.time;
    });

    std::vector<Event> event_cnt;
    for (const auto& event : events) {
        if (event.time > n) break;
        if (!event_cnt.empty() && event_cnt.back().time == event.time) {
            event_cnt.back().type += event.type;
        } else {
            event_cnt.push_back(event);
        }
    }

    if (d == 1) {
        int max_works = 0, max_day = -1;
        int min_works = INT_MAX, min_day = -1;
        int current_cnt = 0;
        // 遍历事件，计算最大重叠数量;
        for (const auto& event : event_cnt) {
            current_cnt += event.type;
            if (current_cnt > max_works) {
                max_works = current_cnt;
                max_day = event.time;
            }
            if (current_cnt < min_works) {
                min_works = current_cnt;
                min_day = event.time;
            }
        }
        std::cout << max_day << ' ' << min_day << std::endl;
    } else {
        // 滑动窗口计算最大重叠数量，窗口长度为d
        int lt = 0, rt = 0, current_cnt = 0, max_cnt = 0, min_cnt = INT_MAX;
        // l 取 -, r 取 +, 每次 r - l + 1 < d 时 r++
        int max_day_left = -1, min_day_left = -1;
        while (rt < events.size()) {
            while (rt < events.size() && events[rt].time - events[lt].time + 1 <= d) {
                if (events[rt++].type == +1) {
                    current_cnt++;
                }
            }
            if (rt == events.size()) break;
            // DEBUG(lt << ' ' << rt << ' ' << current_cnt);
            if (current_cnt > max_cnt) {
                max_cnt = current_cnt;
                max_day_left = events[lt].time;
            }
            if (current_cnt < min_cnt) {
                min_cnt = current_cnt;
                min_day_left = events[lt].time;
            }
            do {
                lt++;
                if (events[lt].type == -1) {
                    current_cnt--;
                }
            } while (events[lt + 1].time == events[lt].time);
        }
        std::cout << max_day_left << ' ' << min_day_left << std::endl;
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
#ifdef CFMode
    int t;
    std::cin >> t;
    while (t--) solve();
#else
    solve();
#endif
    return 0;
}