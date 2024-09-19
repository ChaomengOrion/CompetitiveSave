#include <bits/stdc++.h>
#include "C_Lazy_Narek.cpp" // Include the main file to test

using namespace std;

void test_case(const string &input, const string &expected_output) {
    // Redirect cin and cout
    istringstream in(input);
    ostringstream out;
    streambuf *cinbuf = cin.rdbuf();
    streambuf *coutbuf = cout.rdbuf();
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());

    // Call the main function
    main();

    // Restore cin and cout
    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);

    // Compare the output
    assert(out.str() == expected_output);
}

void run_tests() {
    // Test case 1
    test_case("1\n3 5\nnarek\nnarek\nnarek\n", "30\n");

    // Test case 2
    test_case("1\n2 5\nnarek\nnarek\n", "20\n");

    // Test case 3
    test_case("1\n1 5\nnarek\n", "10\n");

    // Test case 4
    test_case("1\n3 5\nnarek\narekn\nrekna\n", "30\n");

    // Test case 5
    test_case("1\n3 5\nnarek\narekn\nrekna\n", "30\n");

    // Test case 6
    test_case("1\n3 5\nnnnnn\nnnnnn\nnnnnn\n", "0\n");

    // Test case 7
    test_case("1\n3 5\nnarek\nnarek\nnnnnn\n", "20\n");

    // Add more test cases as needed
}

int main() {
    run_tests();
    cout << "All tests passed!" << endl;
    return 0;
}