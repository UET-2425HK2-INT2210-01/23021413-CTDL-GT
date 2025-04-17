#include <iostream>
using namespace std;

// Hàm đệ quy để đảo ngược số nguyên
int reverseNumber(int n, int revNum = 0) {
    // Điều kiện dừng khi n = 0
    if (n == 0) {
        return revNum;
    }
    // Lấy chữ số cuối cùng của n và cộng vào revNum
    return reverseNumber(n / 10, revNum * 10 + n % 10);
}

int main() {
    int n = 1234;
    cout << reverseNumber(n) << endl;
    return 0;
}
