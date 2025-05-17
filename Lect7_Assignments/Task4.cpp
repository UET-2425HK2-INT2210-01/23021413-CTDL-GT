// Given an integer number n, your task is to list all binary number of length n.
// Input: The number n comes from the Keyboard
// Output: Binary numbers of length n are written to the screen each in one line.
// Example:

// Keyboard
// 3

// Screen
// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111

#include <iostream>
#include <vector>
using namespace std;

void generateBinary(int n, string current, vector<string>& result) {
    // n: độ dài mong muốn
    // current: chuỗi nhị phân hiện tại
    // result: vector lưu kết quả
    // Trường hợp cơ bản: khi độ dài đạt n thì thêm vào kết quả
    if (current.length() == n) {
        result.push_back(current);
        return;
    }
    
    // Thêm '0' và tiếp tục đệ quy
    generateBinary(n, current + "0", result);
    
    // Thêm '1' và tiếp tục đệ quy
    generateBinary(n, current + "1", result);
}

int main() {
    int n;
    cout << "Nhập độ dài n: ";
    cin >> n;    
    vector<string> binaryNumbers;
    generateBinary(n, "", binaryNumbers);
    for (const string& num : binaryNumbers) {
        cout << num << endl;
    }
    return 0;
}
