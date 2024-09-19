/*
 * @lc app=leetcode.cn id=2332 lang=cpp
 *
 * [2332] 坐上公交的最晚时间
 */
#include <bits/stdc++.h>
// @lc code=start
class Solution {
public:
    int latestTimeCatchTheBus(std::vector<int>& buses, std::vector<int>& passengers, int capacity) {
        // 排序
        std::cin.tie(nullptr)->sync_with_stdio(false);
        std::sort(buses.begin(), buses.end());
        std::sort(passengers.begin(), passengers.end());
        
        int posBus = 0, posPass = 0, passCnt = 0;
        std::vector<int> lastPassOfBus(buses.size(), -1);
        std::vector<int> passCntOfBus(buses.size(), 0);

        while (posBus < buses.size() && posPass < passengers.size()) {
            if (buses[posBus] >= passengers[posPass] && passCnt < capacity) {
                lastPassOfBus[posBus] = posPass;
                passCntOfBus[posBus]++;
                // std::cout << passengers[posPass] << " on bus" << std::endl;
                posPass++;
                passCnt++;
            } else {
                passCnt = 0;
                // std::cout << buses[posBus] << " bus gone" << std::endl;
                posBus++;
            }
        }

        // std::cout << "posPass: " << posPass << ", posBus: " << posBus << std::endl;
        bool passDone = posPass == passengers.size(); // 乘客是否走完
        bool busDone = posBus + 1 == buses.size(); // 公交是否走完
        // std::cout << "passDone: " << passDone << ", busDone: " << busDone << std::endl;
        
        if (passDone && !busDone) {
            return buses.back();
        }
        else {
            posBus = buses.size() - 1;
            while (posBus >= 0) {
                posPass = lastPassOfBus[posBus];
                passCnt = passCntOfBus[posBus] - 1;
                // std::cout << posBus << "'s CNT is " << passCntOfBus[posBus] << std::endl;
                
                if (passCntOfBus[posBus] == 0) {
                    return buses[posBus];
                }
                else if (passCntOfBus[posBus] < capacity) { // 乘客没坐满
                    // std::cout << "乘客没坐满" << std::endl;
                    // std::cout << buses[posBus] << std::endl;
                    // std::cout <<  passengers[posPass] << std::endl;
                
                    if (buses[posBus] != passengers[posPass]) {
                        return buses[posBus];
                    }
                }
                
                while (passCnt > 0) {
                    if (passengers[posPass - 1] < passengers[posPass] - 1) {
                        break;
                    } else {
                        passCnt--;
                        posPass--;
                    }
                }

                // std::cout << posPass << std::endl;
                
                if (posPass == 0 || passengers[posPass - 1] < passengers[posPass] - 1) {
                    return passengers[posPass] - 1;
                }
                else {
                    posBus--;
                }
            }
            return -114;
        }
    }
};
// @lc code=end

