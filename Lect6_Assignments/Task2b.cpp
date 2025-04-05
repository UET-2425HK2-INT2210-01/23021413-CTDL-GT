// MAX_HEAP:  
//             35
//           /    \
//         20      14
//        /  \    /  \
//       13   10 8    7
//      / \   /
//     6   3 2
//    /
//   1
//  /
// 0
// MIN_HEAP:
//            0
//         /    \
//       1       7
//      /  \    /  \
//     2    3  8    10
//    / \   / \
//   6  13 20 14
//  /
// 35
/*
   2. Given a list of integer numbers: 2, 1, 10, 6, 3, 8, 7, 13, 20.
    - Draw the heap tree after inserting values: 14, 0, 35
*/
#include <iostream>  
using namespace std; 
// Hàm in heap dưới dạng cây nhị phân
void printHeap(int heap[], int size) {
    int level = 1;         // Bắt đầu từ level 1 (gốc)
    int elementsInLevel = 1; // Số phần tử ở level hiện tại
    int count = 0;         // Đếm số phần tử đã in   
    while (count < size) { // Lặp đến khi in hết tất cả phần tử
        // Tính số khoảng trắng cần in trước mỗi level
        int spaces = (1 << (level-1)) - 1; // 2^(level-1) - 1 khoảng trắng
        for (int i = 0; i < spaces; i++) 
            cout << " "; // In khoảng trắng để căn lề       
        // In các phần tử trong level hiện tại
        for (int i = 0; i < elementsInLevel && count < size; i++) {
            cout << heap[count++]; // In giá trị và tăng biến đếm
            if (i < elementsInLevel - 1 && count < size) {
                // Tính khoảng cách giữa các phần tử
                for (int j = 0; j < (1 << level) - 1; j++) 
                    cout << " "; // In khoảng cách
            }
        }
        cout << endl; // Xuống dòng khi kết thúc level     
        // Tăng level và số phần tử ở level tiếp theo
        level++;
        elementsInLevel *= 2; // Số phần tử tăng gấp đôi mỗi level
    }
    cout << endl; // Dòng trống phân cách
}
// Hàm điều chỉnh Max-Heap từ dưới lên
void maxHeapifyUp(int heap[], int index) {
    while (index > 0) { // Lặp khi chưa đến gốc
        int parent = (index - 1) / 2; // Tính chỉ số nút cha
        if (heap[index] > heap[parent]) { // Nếu nút con > cha
            swap(heap[index], heap[parent]); // Đổi chỗ
            index = parent; // Tiếp tục kiểm tra với cha mới
        } else {
            break; // Dừng nếu đúng tính chất heap
        }
    }
}
// Hàm điều chỉnh Min-Heap từ dưới lên
void minHeapifyUp(int heap[], int index) {
    while (index > 0) { // Lặp khi chưa đến gốc
        int parent = (index - 1) / 2; // Tính chỉ số nút cha
        if (heap[index] < heap[parent]) { // Nếu nút con < cha
            swap(heap[index], heap[parent]); // Đổi chỗ
            index = parent; // Tiếp tục kiểm tra với cha mới
        } else {
            break; // Dừng nếu đúng tính chất heap
        }
    }
}
int main() {
    const int MAX_SIZE = 20; // Kích thước tối đa của heap
    int maxHeap[MAX_SIZE] = {2, 1, 10, 6, 3, 8, 7, 13, 20}; // Max-Heap ban đầu
    int minHeap[MAX_SIZE] = {2, 1, 10, 6, 3, 8, 7, 13, 20}; // Min-Heap ban đầu
    int maxSize = 9; // Kích thước hiện tại của maxHeap
    int minSize = 9; // Kích thước hiện tại của minHeap    
    // Các giá trị cần chèn thêm
    int toInsert[] = {14, 0, 35};
    int insertSize = 3;    
    // Chèn vào Max-Heap
    for (int i = 0; i < insertSize; i++) {
        maxHeap[maxSize] = toInsert[i]; // Thêm vào cuối mảng
        maxHeapifyUp(maxHeap, maxSize); // Điều chỉnh heap
        maxSize++; // Tăng kích thước
    }    
    // Chèn vào Min-Heap
    for (int i = 0; i < insertSize; i++) {
        minHeap[minSize] = toInsert[i]; // Thêm vào cuối mảng
        minHeapifyUp(minHeap, minSize); // Điều chỉnh heap
        minSize++; // Tăng kích thước
    }    
    // In kết quả
    cout << "Max-Heap sau khi chen:\n";
    printHeap(maxHeap, maxSize);    
    cout << "Min-Heap sau khi chen:\n";
    printHeap(minHeap, minSize);    
    return 0; // Kết thúc chương trình
}
