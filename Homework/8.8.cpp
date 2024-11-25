#include <iostream>

const int SIZE = 5;
unsigned int values[SIZE] = {2, 4, 6, 8, 10};

int main() {
    // b) Declare a pointer vPtr that points to an object of type unsigned int.
    unsigned int* vPtr;

    // c) Use a for statement to print the elements of array values using array subscript notation.
    for (int i = 0; i < SIZE; ++i) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;

    // d) Write two separate statements that assign the starting address of array values to pointer variable vPtr.
    vPtr = values;
    vPtr = &values[0];

    // e) Use a for statement to print the elements of array values using pointer/offset notation.
    for (int i = 0; i < SIZE; ++i) {
        std::cout << *(vPtr + i) << " ";
    }
    std::cout << std::endl;

    // f) Use a for statement to print the elements of array values using pointer/offset notation with the array name as the pointer.
    for (int i = 0; i < SIZE; ++i) {
        std::cout << *(values + i) << " ";
    }
    std::cout << std::endl;

    // g) Use a for statement to print the elements of array values by subscripting the pointer to the array.
    for (int i = 0; i < SIZE; ++i) {
        std::cout << vPtr[i] << " ";
    }
    std::cout << std::endl;

    // h) Refer to the fifth element of values using array subscript notation, pointer/offset notation with the array name as the pointer, pointer subscript notation and pointer/offset notation.
    std::cout << values[4] << std::endl;
    std::cout << *(values + 4) << std::endl;
    std::cout << vPtr[4] << std::endl;
    std::cout << *(vPtr + 4) << std::endl;

    // i) What address is referenced by vPtr + 3? What value is stored at that location?
    std::cout << "Address referenced by vPtr + 3: " << (vPtr + 3) << std::endl;
    std::cout << "Value stored at that location: " << *(vPtr + 3) << std::endl;

    // j) Assuming that vPtr points to values[4], what address is referenced by vPtr -= 4? What value is stored at that location?
    vPtr = &values[4];
    vPtr -= 4;
    std::cout << "Address referenced by vPtr -= 4: " << vPtr << std::endl;
    std::cout << "Value stored at that location: " << *vPtr << std::endl;

    return 0;
}