#include <iostream>

using namespace std;

const int CAPACITY = 10;

void printBoardingPass(int seatNumber) {
    cout << "Boarding Pass: Seat Number " << seatNumber + 1;
    if (seatNumber < 5) {
        cout << " (First Class)" << endl;
    } else {
        cout << " (Economy)" << endl;
    }
}

int main() {
    bool seats[CAPACITY] = {false}; // 初始化所有座位为空
    int choice;

    while (true) {
        cout << "Please type 1 for \"First Class\"" << endl;
        cout << "Please type 2 for \"Economy\"" << endl;
        cin >> choice;

        if (choice == 1) {
            bool assigned = false;
            for (int i = 0; i < 5; ++i) {
                if (!seats[i]) {
                    seats[i] = true;
                    printBoardingPass(i);
                    assigned = true;
                    break;
                }
            }
            if (!assigned) {
                cout << "First Class is full. Would you like to be placed in Economy? (1 for Yes, 0 for No): ";
                int response;
                cin >> response;
                if (response == 1) {
                    choice = 2; // 切换到经济舱
                } else {
                    cout << "Next flight leaves in 3 hours." << endl;
                }
            }
        }

        if (choice == 2) {
            bool assigned = false;
            for (int i = 5; i < CAPACITY; ++i) {
                if (!seats[i]) {
                    seats[i] = true;
                    printBoardingPass(i);
                    assigned = true;
                    break;
                }
            }
            if (!assigned) {
                cout << "Economy is full. Would you like to be placed in First Class? (1 for Yes, 0 for No): ";
                int response;
                cin >> response;
                if (response == 1) {
                    choice = 1; // 切换到头等舱
                } else {
                    cout << "Next flight leaves in 3 hours." << endl;
                }
            }
        }

        // 检查是否所有座位都已满
        bool allFull = true;
        for (int i = 0; i < CAPACITY; ++i) {
            if (!seats[i]) {
                allFull = false;
                break;
            }
        }
        if (allFull) {
            cout << "All seats are full. Next flight leaves in 3 hours." << endl;
            break;
        }
    }

    return 0;
}