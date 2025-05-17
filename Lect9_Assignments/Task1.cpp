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

// Hàm hoán đổi giá trị
void swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm phân hoạch (partition) cho Quick Sort
int partition(vector<double>& arr, int low, int high) {
    double pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = (low - 1); // Chỉ số của phần tử nhỏ hơn pivot
    
    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn pivot
        if (arr[j] < pivot) {
            i++; // Tăng chỉ số phần tử nhỏ hơn
            swap(&arr[i], &arr[j]); // Hoán đổi phần tử
        }
    }
    swap(&arr[i + 1], &arr[high]); // Đặt pivot vào đúng vị trí
    return (i + 1); // Trả về vị trí phân hoạch

    // Chọn pivot (thường là phần tử cuối)
    // Sắp xếp các phần tử nhỏ hơn pivot về bên trái
    // Các phần tử lớn hơn pivot về bên phải
    // Trả về vị trí của pivot sau khi phân hoạch
}

// Hàm Quick Sort
void quickSort(vector<double>& arr, int low, int high) {
    if (low < high) {
        // pi là chỉ số phân hoạch
        int pi = partition(arr, low, high);
        // Điều kiện dừng khi low >= high
        // Gọi đệ quy cho 2 nửa trái và phải của pivot
        
        // Sắp xếp đệ quy các phần trước và sau phân hoạch
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;    
    vector<double> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i]; 
    }  
    quickSort(numbers, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " "; 
        cout << numbers[i];
    }   
    return 0;
}
