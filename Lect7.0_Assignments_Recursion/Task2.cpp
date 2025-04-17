#include <iostream>
using namespace std;

// Hàm đệ quy tính giai thừa của n
int giaiThua(int n) {
    // Điều kiện dừng khi n = 0 hoặc n = 1
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * giaiThua(n - 1);
}

int main() {
    int n = 5;
    cout << giaiThua(n) << endl;
    return 0;
}
