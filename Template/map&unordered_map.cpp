#include <iostream>
#include <sys/time.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>

struct custom_hash {
    static int splitmix64(int x) {
        //x ^= x << 13;
        //x ^= x >> 7;
        //x ^= x << 17;
        return x ^ (x << 1); 
    }
 
    size_t operator()(int x) const {
        static const int FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int kRunTime1 = 1000*1000;     // 循环次数
const int kRunTime2 = 1000*10000;
int main()
{
    std::vector<std::pair<int, int>> vec;
    std::map<int, int> mp;
    std::unordered_map<int, int, custom_hash> unordermp;

    timeval st, et;

    std::cout << "插入个数 = " << kRunTime1 << std::endl;
    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime1; ++i)
    {
        mp.insert(std::make_pair(i, i));
    }
    gettimeofday(&et, NULL);
    std::cout << "1 有序map测试时间insert time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime1; ++i)
    {
        unordermp.insert(std::make_pair(i, i));
    }
    gettimeofday(&et, NULL);
    std::cout << "1 无序map测试时间insert time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime1; ++i)
    {
        vec.push_back(std::make_pair(i, i));
    }
    gettimeofday(&et, NULL);
    std::cout << "1 vector测试时间push_back time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    std::cout << "查询&修改个数 = " << kRunTime1 << std::endl;
    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime1; ++i)
    {
        mp[i]++;
    }
    gettimeofday(&et, NULL);
    std::cout << "1 有序map测试时间 time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime1; ++i)
    {
        unordermp[i]++;
    }
    gettimeofday(&et, NULL);
    std::cout << "1 无序map测试时间 time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime1; ++i)
    {
        vec[i].first++;
    }
    gettimeofday(&et, NULL);
    std::cout << "1 vector测试时间 time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    std::cout << "遍历个数 = " << kRunTime1 << std::endl;
    gettimeofday(&st, NULL);
    int temp = 0;
    for(auto [k, v] : mp)
    {
        temp += v;
    }
    gettimeofday(&et, NULL);
    std::cout << "1 有序map测试时间 time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    gettimeofday(&st, NULL);
    temp = 0;
    for(auto [k, v] : unordermp)
    {
        temp += v;
    }
    gettimeofday(&et, NULL);
    std::cout << "1 无序map测试时间 time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    gettimeofday(&st, NULL);
    temp = 0;
    for (int i = 0; i < kRunTime1; i++) {
        temp += vec[i].first;
    }
    gettimeofday(&et, NULL);
    std::cout << "1 vector测试时间 time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    std::cout << "\n插入个数 = " << kRunTime2 << std::endl;
    mp.clear();
    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime2; ++i)
    {
        mp.insert(std::make_pair(i, i));
    }
    gettimeofday(&et, NULL);
    std::cout << "2 有序map测试时间insert  time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    mp.clear();
    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime2; ++i)
    {
        mp.emplace(i, i);
    }
    gettimeofday(&et, NULL);
    std::cout << "2 有序map测试时间emplace time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    unordermp.clear();
    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime2; ++i)
    {
        unordermp.insert(std::make_pair(i, i));
    }
    gettimeofday(&et, NULL);
    std::cout << "2 无序map测试时间insert  time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    unordermp.clear();
    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime2; ++i)
    {
        unordermp.emplace(i, i);
    }
    gettimeofday(&et, NULL);
    std::cout << "2 无序map测试时间emplace time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    vec.clear();
    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime2; ++i)
    {
        vec.push_back(std::make_pair(i, i));
    }
    gettimeofday(&et, NULL);
    std::cout << "2 vector测试时间push_back time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    vec.clear();
    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime2; ++i)
    {
        vec.emplace_back(i, i);
    }
    gettimeofday(&et, NULL);
    std::cout << "2 vector测试时间emplace_back time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    vec.clear();
    vec.reserve(kRunTime2);
    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime2; ++i)
    {
        vec.push_back(std::make_pair(i, i));
    }
    gettimeofday(&et, NULL);
    std::cout << "2 vector+reserve测试时间push_back time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    vec.clear();
    vec.reserve(kRunTime2);
    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime2; ++i)
    {
        vec.emplace_back(i, i);
    }
    gettimeofday(&et, NULL);
    std::cout << "2 vector+reserve测试时间emplace_back time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    std::cout << "查询&修改个数 = " << kRunTime2 << std::endl;
    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime2; ++i)
    {
        mp[i]++;
    }
    gettimeofday(&et, NULL);
    std::cout << "1 有序map测试时间 time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime2; ++i)
    {
        unordermp[i]++;
    }
    gettimeofday(&et, NULL);
    std::cout << "1 无序map测试时间 time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    gettimeofday(&st, NULL);
    for(int i = 0; i < kRunTime2; ++i)
    {
        vec[i].first++;
    }
    gettimeofday(&et, NULL);
    std::cout << "1 vector测试时间 time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    std::cout << "遍历个数 = " << kRunTime2 << std::endl;
    gettimeofday(&st, NULL);
    temp = 0;
    for(auto [k, v] : mp)
    {
        temp += v;
    }
    gettimeofday(&et, NULL);
    std::cout << "2 有序map测试时间 time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    gettimeofday(&st, NULL);
    temp = 0;
    for(auto [k, v] : unordermp)
    {
        temp += v;
    }
    gettimeofday(&et, NULL);
    std::cout << "2 无序map测试时间 time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;

    gettimeofday(&st, NULL);
    temp = 0;
    for (int i = 0; i < kRunTime2; i++) {
        temp += vec[i].first;
    }
    gettimeofday(&et, NULL);
    std::cout << "2 vector测试时间 time:" << (et.tv_sec-st.tv_sec)*1000 + (et.tv_usec-st.tv_usec)/1000 << "ms" << std::endl;
    return 0;
}
