#include <iostream>
using namespace std;

// Hàm đệ quy tính lũy thừa x^n
int luyThua(int x, int n) {
    // Điều kiện dừng khi n = 0, x^0 = 1
    if (n == 0) {
        return 1;
    }
    // Gọi đệ quy: x^n = x * x^(n-1)
    return x * luyThua(x, n - 1);
}

int main() {
    int x = 2, n = 3;
    cout << luyThua(x, n) << endl;
    return 0;
}
