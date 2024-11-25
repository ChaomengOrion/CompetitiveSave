#include <iostream>

// b) Function prototype for function zero
void zero(long bigIntegers[]);

// d) Function prototype for function add1AndSum
int add1AndSum(int oneTooSmall[]);

int main() {
    long bigIntegers[5] = {1, 2, 3, 4, 5};
    int oneTooSmall[5] = {1, 2, 3, 4, 5};

    zero(bigIntegers);

    for (int i = 0; i < 5; ++i) {
        std::cout << bigIntegers[i] << " ";
    }
    std::cout << std::endl;

    int sum = add1AndSum(oneTooSmall);
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}

// a) Function header for function zero
void zero(long bigIntegers[]) {
    for (int i = 0; i < 5; ++i) {
        bigIntegers[i] = 0;
    }
}

// c) Function header for function add1AndSum
int add1AndSum(int oneTooSmall[]) {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        oneTooSmall[i] += 1;
        sum += oneTooSmall[i];
    }
    return sum;
}