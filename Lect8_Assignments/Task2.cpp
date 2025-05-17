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

bool isSubsetSum(vector<int>& ages, int n, int X) {
    // Tạo bảng DP kích thước (n+1) x (X+1)
    vector<vector<bool>> dp(n + 1, vector<bool>(X + 1, false));
    // Tạo bảng 2 chiều kích thước (n+1)x(X+1)
    // dp[i][j] = true nếu có thể tạo tổng j từ i phần tử đầu tiên
    // Với tổng = 0, luôn trả về true (không chọn phần tử nào)
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Với n = 0 và tổng > 0, luôn false
    for (int j = 1; j <= X; j++)
        dp[0][j] = false;
    // Với 0 phần tử, không thể tạo tổng > 0
    // Điền bảng DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= X; j++) {
            if (j < ages[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - ages[i - 1]];
          // Nếu tuổi hiện tại > tổng j: không thể chọn
          // Ngược lại: có thể chọn hoặc không chọn phần tử hiện tại
        }
    }

    return dp[n][X];
}

int main() {
    int n, X;
    cin >> n >> X;

    vector<int> ages(n);
    for (int i = 0; i < n; i++) {
        cin >> ages[i];
    }

    if (isSubsetSum(ages, n, X)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
