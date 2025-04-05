// MAX_HEAP:  
//          20
//        /    \
//       13     10
//      / \     / \
//     6   3   8   7
//    / \
//   2   1
// MIN_HEAP:
//          1
//        /   \
//       2      7
//      / \    / \
//     6   3  10  8
//    / \
//   13 20
// MIX_HEAP:
//          20
//        /    \
//       13     8
//      / \    / \
//     10   3 2   7
//    / \
//   1   6

/*
   2. Given a list of integer numbers: 2, 1, 10, 6, 3, 8, 7, 13, 20.
    - Draw the heap tree
*/

#include <iostream>  
using namespace std; 
// Hàm in heap dưới dạng cây nhị phân
void printHeapTree(int heap[], int size) {
    int level = 1;         // Bắt đầu từ level 1 (gốc)
    int elementsInLevel = 1; // Số phần tử ở level hiện tại (bắt đầu bằng 1)
    int count = 0;         // Đếm số phần tử đã in
    while (count < size) { // Lặp đến khi in hết tất cả phần tử
        // In khoảng trắng để căn lề cho đẹp
        for (int i = 0; i < (elementsInLevel/2); i++) {
            cout << "  ";  // 2 khoảng trắng cho mỗi phần tử
        }
        // In các phần tử trong level hiện tại
        for (int i = 0; i < elementsInLevel && count < size; i++) {
            cout << heap[count++]; // In giá trị và tăng biến đếm
            if (i < elementsInLevel - 1 && count < size) {
                cout << " ";       // In khoảng cách giữa các phần tử
            }
        }
        cout << endl; // Xuống dòng khi kết thúc level
        // Tăng level và số phần tử ở level tiếp theo (gấp đôi)
        level++;
        elementsInLevel *= 2;
    }
    cout << endl; // Dòng trống phân cách giữa các heap
}

// Hàm điều chỉnh max heap (cha lớn hơn con)
void maxHeapify(int arr[], int n, int i) {
    int largest = i;       // Coi nút hiện tại là lớn nhất
    int left = 2 * i + 1;  // Chỉ số nút con trái
    int right = 2 * i + 2; // Chỉ số nút con phải
    // So sánh với con trái
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // So sánh với con phải
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // Nếu nút hiện tại không phải lớn nhất
    if (largest != i) {
        swap(arr[i], arr[largest]); // Đổi chỗ với nút lớn hơn
        maxHeapify(arr, n, largest); // Đệ quy điều chỉnh tiếp
    }
}
// Hàm điều chỉnh min heap (cha nhỏ hơn con)
void minHeapify(int arr[], int n, int i) {
    int smallest = i;     // Coi nút hiện tại là nhỏ nhất
    int left = 2 * i + 1; // Chỉ số nút con trái
    int right = 2 * i + 2;// Chỉ số nút con phải
    // So sánh với con trái
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    // So sánh với con phải
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    // Nếu nút hiện tại không phải nhỏ nhất
    if (smallest != i) {
        swap(arr[i], arr[smallest]); // Đổi chỗ với nút nhỏ hơn
        minHeapify(arr, n, smallest); // Đệ quy điều chỉnh tiếp
    }
}
// Hàm xây dựng max heap từ mảng bất kỳ
void buildMaxHeap(int arr[], int n) {
    // Bắt đầu từ nút cha cuối cùng (n/2 - 1) và điều chỉnh ngược lên gốc
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}
// Hàm xây dựng min heap từ mảng bất kỳ
void buildMinHeap(int arr[], int n) {
    // Tương tự như max heap nhưng dùng minHeapify
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}
int main() {
    // Mảng số ban đầu
    int nums[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    int n = sizeof(nums)/sizeof(nums[0]); // Tính số phần tử
    // Tạo các bản sao của mảng gốc
    int maxHeap[n], minHeap[n], mixHeap[n];
    // Sao chép dữ liệu từ nums sang các heap
    for(int i = 0; i < n; i++) {
        maxHeap[i] = nums[i];
        minHeap[i] = nums[i];
        mixHeap[i] = nums[i];
    }
    // Xây dựng và in MAX_HEAP
    buildMaxHeap(maxHeap, n);
    cout << "MAX_HEAP:\n";
    printHeapTree(maxHeap, n); 
    // Xây dựng và in MIN_HEAP
    buildMinHeap(minHeap, n);
    cout << "MIN_HEAP:\n";
    printHeapTree(minHeap, n);  
    // Tạo MIX_HEAP tùy chỉnh (không phải heap tiêu chuẩn)
    int customMix[] = {20, 13, 8, 10, 3, 2, 7, 1, 6};
    cout << "MIX_HEAP:\n";
    printHeapTree(customMix, n);    
    return 0; // Kết thúc chương trình
}
