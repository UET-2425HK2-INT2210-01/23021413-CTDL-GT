#include <iostream>
using namespace std;

// Hàm đệ quy để tính tổng từ 1 đến n
int deQuy(int n) {
    // Điều kiện dừng khi n = 0
    if (n == 0) {
        return 0;
    }
    // Gọi đệ quy: sum(n) = n + sum(n - 1)
    return n + deQuy(n - 1);
}

int main() {
    int n = 5;
    cout << deQuy(n) << endl;
    return 0;
}
