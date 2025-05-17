// Given a list of real numbers, your task is to implement a ‘quick’ sorting algorithm to order these numbers increasingly.
// Input: The input consists of n in the first line and n real numbers separated by spaces in the next n lines.
// Output: The sorted numbers and two numbers are separated by a space character.
// Input
// 6
// 3 5 2 2 1 8

// Output
// 1 2 2 3 5 8

#include <iostream>
#include <vector>
using namespace std;
// Hàm phân hoạch (partition) cho Quick Sort
int partition(vector<double>& arr, int low, int high) {
    // arr: mảng cần xắp xếp
    // low: chỉ số bắt đầu
    // high: chỉ số kết thúc
    double pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = (low - 1); // Chỉ số của phần tử nhỏ hơn pivot
    
    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn pivot
        if (arr[j] < pivot) {
            i++; // Tăng chỉ số phần tử nhỏ hơn
            swap(arr[i], arr[j]); // Hoán đổi phần tử
        }
    }
    swap(arr[i + 1], arr[high]); // Đặt pivot vào đúng vị trí
    return (i + 1); // Trả về vị trí phân hoạch
}

// Hàm Quick Sort
void quickSort(vector<double>& arr, int low, int high) {
    if (low < high) {
        // pi là chỉ số phân hoạch
        int pi = partition(arr, low, high);      
        // Sắp xếp đệ quy các phần trước và sau phân hoạch
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n; 
    
    vector<double> numbers(n);
    for (int i = 0; i < n; i++) { cin >> numbers[i]; }
    quickSort(numbers, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " "; // Thêm dấu cách giữa các số
        cout << numbers[i];
    }
    return 0;
}
