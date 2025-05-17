// Given a list of real numbers, your task is to write a program to sort these numbers increasingly.
// Input: The file ‘numbers.txt’ consists of n real numbers separated by spaces or new line characters.
// Output: The sorted numbers are written to file ‘numbers.sorted’, two numbers are separated by a space character.

// numbers.txt
// 3 5 2
// 2 1 8

// numbers.sorted
// 1 2 2 3 5 8
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("numbers.txt");
    
    vector<double> numbers;
    double num;
    
    while (inputFile >> num) { numbers.push_back(num); } // Thêm số vào cuối vector
    inputFile.close();
    
    sort(numbers.begin(), numbers.end());
    // Iterator trỏ đến phần tử đầu, cuối 
    
    ofstream outputFile("numbers.sorted");
    
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i != 0) {
            outputFile << " "; // Thêm dấu cách trước mỗi số (trừ số đầu tiên)
        }
        outputFile << numbers[i]; // Ghi số hiện tại vào file
    }
    outputFile.close();
    
    return 0;
}
