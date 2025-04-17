#include <iostream>
using namespace std;

// Hàm đệ quy đếm số chữ số của n
int count(int n) {
    // Điều kiện dừng khi n chỉ còn 0 (không còn chữ số nào)
    if (n == 0) {
        return 0;
    }
    // Gọi đệ quy: Đếm số chữ số của n = 1 + đếm số chữ số của n / 10
    return 1 + count(n / 10);
}

int main() {
    int n = 12345;
    cout << count(n) << endl;
    return 0;
}
