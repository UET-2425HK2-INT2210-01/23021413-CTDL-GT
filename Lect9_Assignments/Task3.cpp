// Given n objects each has a weight w and a value v, your task is to select a number of objects with the largest sum of values conditioned that the sum of their weights is not greater than X.
// Input: The input consists of numbers n and X in the first line, and n pairs of natural numbers (weight and value) in the next n lines.
// Output: The largest sum of values identified.
// Input
// 5 10
// 1 1
// 2 2
// 3 3
// 9 9
// 8 10

// Output
// 12

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int X, vector<int>& weights, vector<int>& values, int n) {
    // Tạo bảng DP kích thước (n+1) x (X+1)
    // Tạo bảng 2 chiều với (n+1) hàng (số vật) và (X+1) cột (khối lượng)
    // Khởi tạo tất cả giá trị bằng 0
    vector<vector<int>> dp(n + 1, vector<int>(X + 1, 0));

    // Xây dựng bảng DP từ dưới lên
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= X; w++) { // Duyệt qua từng vật và từng khối lượng có thể
            // Nếu trọng lượng của vật thứ i-1 <= trọng lượng hiện tại w
            if (weights[i - 1] <= w) {
                // Chọn tối ưu giữa việc chọn hoặc không chọn vật này
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                // Không thể chọn vật này
                dp[i][w] = dp[i - 1][w];
                // Nếu có thể chọn vật: so sánh giữa việc chọn hoặc không chọn
                // Nếu không thể chọn: giữ nguyên giá trị từ trước
            }
        }
    }

    return dp[n][X];
}

int main() {
    int n, X;
    cin >> n >> X;
    vector<int> weights(n);
    vector<int> values(n);
    for (int i = 0; i < n; i++) { cin >> weights[i] >> values[i]; }
    cout << knapsack(X, weights, values, n);
    return 0;
}
