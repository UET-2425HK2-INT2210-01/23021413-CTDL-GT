// Given an integer number X and a list A of n natural numbers that are the ages of n students, your task is to find a group students such that the sum of their ages is equal to X.
// Input: The input consists of n and X in the first line, and n natural numbers in the second line separated by spaces.
// Output: Write ‘YES’ if existed, otherwise ‘NO’
// Input
// 6 10
// 2 5 6 2 1 7

// Output
// YES

#include <iostream>
#include <vector>
using namespace std;

// Hàm kiểm tra bằng đệ quy có nhớ
bool isSubsetSum(vector<int>& ages, int n, int X, vector<vector<int>>& memo) {
    // ages: danh sách tuổi học sinh
    // n: số lượng học sinh hiện tại đang xét
    // X: tổng tuổi cần kiểm tra
    // memo: bảng ghi nhớ kết quả
    // Trường hợp cơ sở
    if (X == 0) return true;
    if (n == 0 || X < 0) return false;
    
    // Kiểm tra nếu đã tính toán trước đó
    if (memo[n][X] != -1) return memo[n][X];
    
    // Kiểm tra có thể tạo tổng X bằng cách:
    // 1. Bao gồm tuổi cuối cùng
    // 2. Không bao gồm tuổi cuối cùng
    bool include = isSubsetSum(ages, n - 1, X - ages[n - 1], memo);
    bool exclude = isSubsetSum(ages, n - 1, X, memo);
    
    // Lưu kết quả vào bảng nhớ
    return memo[n][X] = (include || exclude);
}

int main() {
    int n, X;
    cin >> n >> X;
    vector<int> ages(n);
    for (int i = 0; i < n; i++) { cin >> ages[i]; }
    // Khởi tạo bảng nhớ với -1 (chưa tính toán)
    vector<vector<int>> memo(n + 1, vector<int>(X + 1, -1));
    if (isSubsetSum(ages, n, X, memo)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
