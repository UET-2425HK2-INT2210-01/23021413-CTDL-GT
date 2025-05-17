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
    // X: trọng lượng tối đa
    // weights: vector chứa trọng lượng các vật
    // values: vector chứa giá trị các vật
    // n: số lượng vật
    vector<vector<int>> dp(n + 1, vector<int>(X + 1, 0));
    // Tạo bảng 2 chiều kích thước (n+1)x(X+1) khởi tạo giá trị 0
    // dp[i][w] lưu giá trị tối đa khi xét i vật đầu tiên với trọng lượng tối đa w

    // Xây dựng bảng DP từ dưới lên
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= X; w++) {
            // Nếu trọng lượng của vật thứ i-1 <= trọng lượng hiện tại w
            if (weights[i - 1] <= w) {
                // Chọn tối ưu giữa việc chọn hoặc không chọn vật này
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                // Không thể chọn vật này
                dp[i][w] = dp[i - 1][w];
              // Nếu vật hiện tại có thể chọn (trọng lượng <= w):
              // So sánh giữa việc chọn hoặc không chọn vật này
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
