// Last MAX_HEAP:
//           20
//         /    \
//       3       10
//      / \     / \
//     2   1   8   7

// Last MIN_HEAP:
//           1
//         /   \
//       2      7
//      / \    / \
//     20  3  10  8

// Last MIX_HEAP:
//           20
//         /    \
//       10      8
//      / \     / \
//     2   3   1   7
/*
   2. Given a list of integer numbers: 2, 1, 10, 6, 3, 8, 7, 13, 20.
    - Draw the heap tree after deleting: 6, 13, 35
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
// Hàm điều chỉnh Max-Heap từ trên xuống
void maxHeapifyDown(int heap[], int size, int index) {
    int largest = index;   // Coi nút hiện tại là lớn nhất
    int left = 2*index + 1; // Chỉ số nút con trái
    int right = 2*index + 2; // Chỉ số nút con phải
    // So sánh với con trái
    if (left < size && heap[left] > heap[largest])
        largest = left;
    // So sánh với con phải
    if (right < size && heap[right] > heap[largest])
        largest = right;
    // Nếu nút hiện tại không phải lớn nhất
    if (largest != index) {
        swap(heap[index], heap[largest]); // Đổi chỗ với nút lớn hơn
        maxHeapifyDown(heap, size, largest); // Đệ quy điều chỉnh tiếp
    }
}
// Hàm điều chỉnh Min-Heap từ trên xuống
void minHeapifyDown(int heap[], int size, int index) {
    int smallest = index;  // Coi nút hiện tại là nhỏ nhất
    int left = 2*index + 1; // Chỉ số nút con trái
    int right = 2*index + 2; // Chỉ số nút con phải
    // So sánh với con trái
    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    // So sánh với con phải
    if (right < size && heap[right] < heap[smallest])
        smallest = right;
    // Nếu nút hiện tại không phải nhỏ nhất
    if (smallest != index) {
        swap(heap[index], heap[smallest]); // Đổi chỗ với nút nhỏ hơn
        minHeapifyDown(heap, size, smallest); // Đệ quy điều chỉnh tiếp
    }
}
// Hàm xóa phần tử bất kỳ từ heap
bool deleteFromHeap(int heap[], int& size, int value, bool isMaxHeap) {
    // Tìm vị trí phần tử cần xóa
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (heap[i] == value) {
            index = i;
            break;
        }
    }
    if (index == -1) return false; // Không tìm thấy   
    // Thay thế bằng phần tử cuối cùng
    heap[index] = heap[size-1];
    size--; // Giảm kích thước heap    
    // Điều chỉnh heap
    if (isMaxHeap) {
        maxHeapifyDown(heap, size, index);
    } else {
        minHeapifyDown(heap, size, index);
    }
    return true;
}
int main() {
    // Khởi tạo các heap
    int maxHeap[] = {20,13,10,6,3,8,7,2,1};
    int minHeap[] = {1,2,7,6,3,10,8,13,20};
    int mixHeap[] = {20,13,8,10,3,2,7,1,6};
    int maxSize = 9, minSize = 9, mixSize = 9;    
    // Các giá trị cần xóa
    int toDelete[] = {6,13,35};    
    // Xử lý MAX_HEAP
    printHeap(maxHeap, maxSize);
    for (int val : toDelete) {
        if (deleteFromHeap(maxHeap, maxSize, val, true)) {
            cout << "Da xoa " << val << ":\n";
            printHeap(maxHeap, maxSize);
        } else {
            cout << val << " khong ton tai\n";
        }
    }    
    // Xử lý MIN_HEAP
    printHeap(minHeap, minSize);
    for (int val : toDelete) {
        if (deleteFromHeap(minHeap, minSize, val, false)) {
            cout << "Da xoa " << val << ":\n";
            printHeap(minHeap, minSize);
        } else {
            cout << val << " khong ton tai\n";
        }
    }    
    // Xử lý MIX_HEAP (coi như MAX_HEAP)
    printHeap(mixHeap, mixSize);
    for (int val : toDelete) {
        if (deleteFromHeap(mixHeap, mixSize, val, true)) {
            cout << "Da xoa " << val << ":\n";
            printHeap(mixHeap, mixSize);
        } else {
            cout << val << " khong ton tai\n";
        }
    }    
    return 0;
}

