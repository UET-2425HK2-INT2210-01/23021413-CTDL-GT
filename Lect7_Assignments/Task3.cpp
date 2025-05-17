// Given two integer number X and Y, your task is to write a program to find the greatest common divisor of X and Y using recursion.
// Input: Input come from keyboard containing two number X and Y Output: Ouput are written to screen contaning the greatest common divisor. Example:

// Keyboard
// 10
// 50

// Screen
// 10

#include <iostream>
using namespace std;

int gcd(int x, int y) {
    // Trường hợp cơ bản: nếu y = 0 thì GCD là x
    if (y == 0)
        return x;
    // Bước đệ quy: gọi lại hàm với y và x % y
    else
        return gcd(y, x % y);
}

int main() {
    int X, Y;
    cout << "Nhập hai số X và Y: ";
    cin >> X >> Y;
    cout << "Ước chung lớn nhất của " << X << " và " << Y << " là: " << gcd(X, Y);
    return 0;
}
