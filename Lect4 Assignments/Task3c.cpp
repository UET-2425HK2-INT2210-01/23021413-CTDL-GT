3. Draw the 17-entry hash that results from using the hash function h(i) = (i+3) mod
17 to hash keys 1, 3, 18, 8, 23, 35, 11, 36, 20, 16.
c) Assume collisions are handled by chaining.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Ví dụ testcase: 
// Hash table:
// Index 0: NULL
// Index 1: 1 -> NULL
// Index 2: 3 -> NULL
// Index 3: 36 -> NULL
// Index 4: 16 -> NULL
// Index 5: NULL
// Index 6: 18 -> NULL
// Index 7: NULL
// Index 8: NULL
// Index 9: 23 -> NULL
// Index 10: NULL
// Index 11: 35 -> NULL
// Index 12: 11 -> NULL
// Index 13: 20 -> NULL
// Index 14: NULL
// Index 15: 8 -> NULL
// Index 16: NULL
#include <iostream>
#define HASH_SIZE 17  // Cập nhật kích thước bảng băm thành 17
using namespace std;
// Cấu trúc Node cho phương pháp chaining (dùng Linked List)
struct Node
{
    int val;
    Node *next;
};
// Hàm tạo một node mới với giá trị x
Node *make_node(int x)
{
    Node *tmp = new Node;
    tmp->val = x;
    tmp->next = NULL;
    return tmp;
}
// Mảng chứa các phần tử của bảng băm (mỗi phần tử là con trỏ tới danh sách liên kết)
Node *hash_table[HASH_SIZE];
// Hàm băm: h(i) = (i + 3) % 17
int hash_func(int x)
{
    return (x + 3) % HASH_SIZE;  // Công thức băm mới
}
// Hàm chèn giá trị vào bảng băm với phương pháp chaining
void chaining(int x)
{
    int index = hash_func(x);  // Tính toán chỉ số vị trí trong bảng băm
    Node *tmp = make_node(x);  // Tạo một node mới với giá trị x
    // Nếu vị trí đó chưa có phần tử nào, gán node mới vào đó
    if (hash_table[index] == NULL)
    {
        hash_table[index] = tmp;
    }
    else
    {
        // Nếu đã có phần tử, thêm node mới vào đầu danh sách liên kết
        tmp->next = hash_table[index];
        hash_table[index] = tmp;
    }
}
// Hàm in ra các phần tử của bảng băm tại chỉ số index
void print(int index)
{
    Node *tmp = hash_table[index];
    if (tmp == NULL)
    {
        cout << "NULL";  // Nếu vị trí đó không có phần tử nào, in ra NULL
    }
    else
    {
        // Nếu có phần tử, in các giá trị liên tiếp trong danh sách
        while (tmp != NULL)
        {
            cout << tmp->val << " -> ";
            tmp = tmp->next;
        }
        cout << "NULL";  // Kết thúc danh sách liên kết
    }
}
// Hàm main thực hiện việc chèn và in bảng băm
int main()
{
    // Khởi tạo bảng băm với tất cả các vị trí bằng NULL
    for (int i = 0; i < HASH_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
    // Chèn các khóa vào bảng băm
    chaining(1);
    chaining(3);
    chaining(18);
    chaining(8);
    chaining(23);
    chaining(35);
    chaining(11);
    chaining(36);
    chaining(20);
    chaining(16);
    // In toàn bộ bảng băm
    cout << "Hash table:" << endl;
    for (int i = 0; i < HASH_SIZE; i++)
    {
        cout << "Index " << i << ": ";
        print(i);  
        cout << endl;
    }
    return 0;
}
