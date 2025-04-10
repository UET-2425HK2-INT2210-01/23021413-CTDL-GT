// 3. Given a list of integer numbers, your task is to read these numbers into a
// doubly linked list, and implement function count_triplets() to count all
// positions p such that the sum of elements at positions p-1, p, and p+1 is
// zero.

// Input:
// − The first line contains an integer number n which is the number of
// numbers.
// − The second line contains n integer numbers to read into
// count_triplets function

// Output: Write to the screen an integer number that is the result of
// function count_triplets().

// Example
// Keyboard               Screen
// 6                      2
// 5 -3 -2 2 9 -11

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Định nghĩa cấu trúc Node
STRUCT Node
    data: integer
    previous: con trỏ Node  // trỏ đến node trước
    next: con trỏ Node      // trỏ đến node sau

// Khởi tạo Node với giá trị val
FUNCTION Node(val)
    data = val
    previous = NULL
    next = NULL

// Định nghĩa lớp DoubleLinkList
CLASS DoubleLinkList
    PRIVATE:
        head: con trỏ Node  // đầu danh sách
        tail: con trỏ Node   // cuối danh sách

    PUBLIC:
        // Khởi tạo danh sách rỗng
        FUNCTION DoubleLinkList()
            head = NULL
            tail = NULL

        // Thêm phần tử vào cuối danh sách
        FUNCTION append(val)
            Tạo newNode với data = val
            Nếu head == NULL  // danh sách rỗng
                head = tail = newNode
            Ngược lại
                tail->next = newNode
                newNode->previous = tail
                tail = newNode

        // Đếm số bộ ba có tổng bằng 0
        FUNCTION count_triplets()
            count = 0
            temp = head

            // Duyệt từ đầu đến phần tử thứ 3 từ cuối
            TRONG KHI temp != NULL VÀ temp->next != NULL VÀ temp->next->next != NULL
                // Kiểm tra nếu tổng 3 phần tử liên tiếp bằng 0
                NẾU temp->previous != NULL VÀ 
                    temp->previous->data + temp->data + temp->next->data == 0
                    count = count + 1
                temp = temp->next

            TRẢ VỀ count

// Chương trình chính
FUNCTION main()
    Đọc n (số lượng phần tử)
    Tạo list là đối tượng DoubleLinkList

    // Thêm n phần tử vào danh sách
    Lặp n lần:
        Đọc val
        list.append(val)

    // Đếm và in số bộ ba có tổng bằng 0
    In list.count_triplets()
    Kết thúc

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* previous;
    Node* next;
    Node(int val) : data(val), previous(nullptr), next(nullptr) {}
};

class DoubleLinkList {
private:
    Node* head;
    Node* tail;
public:
    DoubleLinkList() : head(nullptr), tail(nullptr) {}
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }
    int count_triplets() {
        int count = 0;
        Node* temp = head;

        while (temp && temp->next && temp->next->next) {
            if (temp->previous->data + temp->data + temp->next->data == 0) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    DoubleLinkList list;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.append(val);
    }
    cout << list.count_triplets() << endl;
    return 0;
}
