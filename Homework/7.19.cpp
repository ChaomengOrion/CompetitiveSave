#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

enum Status { CONTINUE, WON, LOST };

int rollDice() {
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    return die1 + die2;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int totalGames = 1000;
    vector<int> wins(21, 0);
    vector<int> losses(21, 0);
    int totalRolls = 0;

    for (int game = 0; game < totalGames; ++game) {
        int rollCount = 0;
        int myPoint;
        Status gameStatus;
        int sumOfDice = rollDice();
        ++rollCount;

        switch (sumOfDice) {
            case 7:
            case 11:
                gameStatus = WON;
                break;
            case 2:
            case 3:
            case 12:
                gameStatus = LOST;
                break;
            default:
                gameStatus = CONTINUE;
                myPoint = sumOfDice;
                break;
        }

        while (gameStatus == CONTINUE) {
            sumOfDice = rollDice();
            ++rollCount;

            if (sumOfDice == myPoint) {
                gameStatus = WON;
            } else if (sumOfDice == 7) {
                gameStatus = LOST;
            }
        }

        totalRolls += rollCount;

        if (rollCount <= 20) {
            if (gameStatus == WON) {
                ++wins[rollCount - 1];
            } else {
                ++losses[rollCount - 1];
            }
        } else {
            if (gameStatus == WON) {
                ++wins[20];
            } else {
                ++losses[20];
            }
        }
    }

    cout << "Games won on the 1st roll, 2nd roll, ..., 20th roll, and after the 20th roll:\n";
    for (int i = 0; i < 21; ++i) {
        cout << "Roll " << (i + 1) << ": " << wins[i] << endl;
    }

    cout << "\nGames lost on the 1st roll, 2nd roll, ..., 20th roll, and after the 20th roll:\n";
    for (int i = 0; i < 21; ++i) {
        cout << "Roll " << (i + 1) << ": " << losses[i] << endl;
    }

    int totalWins = 0;
    for (int win : wins) {
        totalWins += win;
    }

    cout << "\nChances of winning at craps: " << static_cast<double>(totalWins) / totalGames << endl;
    cout << "Average length of a game of craps: " << static_cast<double>(totalRolls) / totalGames << " rolls" << endl;

    return 0;
}