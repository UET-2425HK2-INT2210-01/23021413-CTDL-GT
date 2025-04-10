// 5. The Stack structure has two following operations:
// − push (x): insert integer number x to the top of the stack
// − pop (): remove the element at the top of the stack
// Start from an empty stack, your task is to implement a stack, perform
// operations from the keyboard and write the resulting stack to the screen

// Input:
// − The first line contains an integer number n which is the number of
// operations
// − The next n lines contain the operation description. One operation is
// in one line in either format:
// ● push x
// ● pop
// where x is the number to push to the stack.

// Output: Write the resulting stack to the screen. Numbers are separated
// by spaces.

// Example
// Keyboard         Screen
// 7                1 2 5
// push 1
// push 2
// push 3
// push 4
// pop
// pop
// push 5

-----------------------------------------------------------------------------------------------------------------------------------------------------------------
< Pseudocode >
// Định nghĩa cấu trúc Node
STRUCT Node
    data: integer
    next: con trỏ Node

// Khởi tạo Node với giá trị val
FUNCTION Node(val)
    data = val
    next = NULL

// Định nghĩa lớp Stack
CLASS Stack
    PRIVATE:
        top: con trỏ Node

    PUBLIC:
        // Khởi tạo stack rỗng
        FUNCTION Stack()
            top = NULL

        // Thêm phần tử x vào đỉnh stack
        FUNCTION push(x)
            Tạo newNode với data = x
            newNode.next = top
            top = newNode

        // Xóa phần tử ở đỉnh stack
        FUNCTION pop()
            Nếu top == NULL thì return
            temp = top
            top = top.next
            Xóa temp

        // In stack từ đỉnh xuống đáy
        FUNCTION printStack()
            temp = top
            Trong khi temp != NULL
                In temp.data
                temp = temp.next
            Xuống dòng

// Chương trình chính
FUNCTION main()
    Đọc n (số lượng thao tác)
    Tạo stack là đối tượng Stack

    Lặp n lần:
        Đọc operation
        Nếu operation == "push"
            Đọc x
            Gọi stack.push(x)
        Ngược lại nếu operation == "pop"
            Gọi stack.pop()

    Gọi stack.printStack()
    Kết thúc

------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;
    
public:
    Stack() : top(nullptr) {}
    
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }
    
    void pop() {
        if (top == nullptr) return;
        
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    
    void printStack() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    
    Stack stack;
    
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "push") {
            int x;
            cin >> x;
            stack.push(x);
        } else if (operation == "pop") {
            stack.pop();
        }
    }
    
    stack.printStack();
    
    return 0;
}
