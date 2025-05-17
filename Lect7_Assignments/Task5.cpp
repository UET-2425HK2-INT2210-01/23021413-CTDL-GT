// Given an integer number n, your task is to list all permutations of length n.
// Input: The number n comes from the Keyboard
// Output: Permutations of length n are written to the screen each in one line.
// Example:

// Keyboard
// 3

// Screen
// 123
// 132
// 213
// 231
// 312
// 321

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generatePermutations(int n) {
    // Tạo vector chứa các số từ 1 đến n
    vector<int> numbers;
    for (int i = 1; i <= n; ++i) {
        numbers.push_back(i);
    }
    
    // Sử dụng hàm next_permutation để sinh tất cả các hoán vị
    do {
        // In hoán vị hiện tại
        for (int num : numbers) { cout << num; }
        cout << endl;
    } while (next_permutation(numbers.begin(), numbers.end()));
}

int main() {
    int n;
    cout << "Nhập số n: ";
    cin >> n;
    generatePermutations(n); 
    return 0;
}
