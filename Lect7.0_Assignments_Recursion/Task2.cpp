#include <iostream>
using namespace std;

// Hàm đệ quy tính giai thừa của n
int factorial(int n) {
    // Điều kiện dừng khi n = 0 hoặc n = 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Gọi đệ quy: factorial(n) = n * factorial(n - 1)
    return n * factorial(n - 1);
}

int main() {
    int n = 5;
    cout << factorial(n) << endl;
    return 0;
}
