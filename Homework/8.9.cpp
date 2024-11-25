#include <iostream>

int main() {
    long value1 = 200000;
    long value2;

    // a) Declare the variable longPtr to be a pointer to an object of type long.
    long* longPtr;

    // b) Assign the address of variable value1 to pointer variable longPtr.
    longPtr = &value1;

    // c) Print the value of the object pointed to by longPtr.
    std::cout << *longPtr << std::endl;

    // d) Assign the value of the object pointed to by longPtr to variable value2.
    value2 = *longPtr;

    // e) Print the value of value2.
    std::cout << value2 << std::endl;

    // f) Print the address of value1.
    std::cout << &value1 << std::endl;

    // g) Print the address stored in longPtr. Is the value printed the same as value1’s address?
    std::cout << longPtr << std::endl;

    return 0;
}