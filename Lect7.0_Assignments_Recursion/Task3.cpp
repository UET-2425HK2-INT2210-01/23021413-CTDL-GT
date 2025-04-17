#include <iostream>
using namespace std;

// Hàm đệ quy tính số Fibonacci thứ n
int fibonacci(int n) {
    // Điều kiện dừng khi n = 0 hoặc n = 1
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // Gọi đệ quy: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 6;
    cout << fibonacci(n) << endl;
    return 0;
}
