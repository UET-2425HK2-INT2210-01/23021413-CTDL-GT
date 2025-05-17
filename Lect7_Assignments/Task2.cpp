// Given a matrix A of m rows (numbered from 1 to m) and n columns (numbered from 1 to n) containing integer numbers, your task is to write a program to find the rectangle with the largest sum.
// Input: The file ‘matrix.txt’ consists of m + 1 lines. The first line consists of m and n. The next m lines each has n integer numbers separated by a spaces.
// Output: Write to file ‘matrix.out’ 5 numbers: r1 c1 r2 r2 s indicating that the rectangle from (r1, c1) to (r2, c2) has the largest sum (i.e. s).
// Example
// Matrix.txt

// 3 5
// -1 -1 -1 -1 2
// -1 2 -2 1 3
// 2 -1 -1 -1 -1

// Matrix.out
// 1 4 2 5 5
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    // Mở file đầu vào
    ifstream inputFile("matrix.txt");
    ofstream outputFile("matrix.out");
    int m, n;
    inputFile >> m >> n;

 
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> matrix[i][j];
        }
    }

    int maxSum = INT_MIN;
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;

    // Tính toán prefix sum theo hàng để tối ưu, mỗi hàng có 1 mảng prefix sum riêng
    // prefix[i][j] chứa tổng các phần tử từ cột 0 đến cột j-1 của hàng i
    vector<vector<int>> prefix(m, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            prefix[i][j + 1] = prefix[i][j] + matrix[i][j];
        }
    }

    // Duyệt qua tất cả các cột có thể (c1, c2)
    for (int left = 0; left < n; ++left) {
        for (int right = left; right < n; ++right) {
            // Áp dụng thuật toán Kadane theo chiều dọc, duyệt qua tất cả các cặp cột (left, right)
            // Với mỗi cặp cột, áp dụng thuật toán Kadane theo chiều dọc để tìm hình chữ nhật có tổng lớn nhất
            int currentSum = 0;
            int startRow = 0;
            int tempMax = INT_MIN;
            int tempR1 = 0, tempR2 = 0;

            for (int row = 0; row < m; ++row) {
                // Tính tổng của hàng row từ cột left đến right
                int rowSum = prefix[row][right + 1] - prefix[row][left];
                
                currentSum += rowSum;
                
                // Cập nhật tổng tạm thời
                if (currentSum > tempMax) {
                    tempMax = currentSum;
                    tempR1 = startRow;
                    tempR2 = row;
                }
                
                // Nếu tổng âm thì reset
                if (currentSum < 0) {
                    currentSum = 0;
                    startRow = row + 1;
                }
            }

            // So sánh với tổng lớn nhất hiện có
            if (tempMax > maxSum) {
                maxSum = tempMax;
                r1 = tempR1;
                c1 = left;
                r2 = tempR2;
                c2 = right;
            }
        }
    }

    // Ghi kết quả vào file (chuyển từ 0-based sang 1-based)
    outputFile << r1 + 1 << " " << c1 + 1 << " " << r2 + 1 << " " << c2 + 1 << " " << maxSum;
    inputFile.close();
    outputFile.close();

    return 0;
}
