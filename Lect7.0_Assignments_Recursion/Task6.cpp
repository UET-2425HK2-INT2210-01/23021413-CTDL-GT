#include <iostream>
using namespace std;

// Hàm đệ quy tính tổng các chữ số của n
int sum(int n) {
    // Điều kiện dừng khi n = 0 (không còn chữ số nào)
    if (n == 0) {
        return 0;
    }
    // Gọi đệ quy: Tổng các chữ số của n = chữ số cuối cùng + tổng các chữ số còn lại
    return n % 10 + sum(n / 10);
}

int main() {
    int n = 1234;
    cout << sum(n) << endl;
    return 0;
}
