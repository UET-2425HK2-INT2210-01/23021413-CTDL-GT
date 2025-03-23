// Hy vọng đầu ra là: 13 3 18 8 23 35 11 36 20 16 -1 -1 -1 -1 -1 -1 -1 
#include <iostream>
#define HASH_SIZE 17  // Cập nhật kích thước bảng băm thành 17
using namespace std;
// Hàm băm: h(i) = (i + 3) % 17
int hash_func(int x) {
    return (x + 3) % HASH_SIZE;  // Công thức băm mới
}
// Hàm chèn giá trị vào bảng băm với phương pháp linear probing
void insert(int hashTable[], int x) {
    int index = hash_func(x);  // Tính toán chỉ số vị trí trong bảng băm
    // Kiểm tra và thăm dò tuyến tính nếu có va chạm
    while (hashTable[index] != -1) {
        index = (index + 1) % HASH_SIZE;  // Thăm dò tiếp theo theo modulo HASH_SIZE
    }
    hashTable[index] = x;  // Chèn giá trị vào bảng tại vị trí tìm được
}
// Hàm in ra bảng băm
void print(int hashTable[]) {
    for (int i = 0; i < HASH_SIZE; i++) {
        cout << hashTable[i] << " ";  // In các giá trị trong bảng băm
    }
    cout << endl;
}
int main() {
    // Khởi tạo bảng băm với các giá trị là -1 (vị trí trống)
    int hashTable[HASH_SIZE];
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = -1;  // Khởi tạo các ô trong bảng băm là -1 (vị trí trống)
    }
    // Chèn các khóa vào bảng băm
    insert(hashTable, 1);
    insert(hashTable, 3);
    insert(hashTable, 18);
    insert(hashTable, 8);
    insert(hashTable, 23);
    insert(hashTable, 35);
    insert(hashTable, 11);
    insert(hashTable, 36);
    insert(hashTable, 20);
    insert(hashTable, 16);
    // In bảng băm
    print(hashTable);
    return 0;
}
