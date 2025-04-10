// 4. The Queue structure has two following operations:
// − enqueue (x): insert integer number x at the tail the queue.
// − dequeue (): remove the element at the head of the queue.
// Start from an empty queue, your task is to implement a queue, perform
// operations from the keyboard and write the resulting queue to the
// screen.

// Input:
// − The first line contains an integer number n which is the number of
// operations
// − The next n lines contain the operation description. One operation is
// in one line in either format:
// ● enqueue x
// ● dequeue
// where x is the number to enqueue

// Output: Write the resulting queue to the screen. Numbers are separated
// by spaces.

// Example
// Keyboard      Screen
// 7             3 4 5
// enqueue 1
// enqueue 2
// enqueue 3
// enqueue 4
// dequeue
// dequeue
// enqueue 5

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Định nghĩa cấu trúc Node
STRUCT Node
    data: integer
    next: con trỏ Node

// Khởi tạo Node với giá trị val
FUNCTION Node(val)
    data = val
    next = NULL

// Định nghĩa lớp Queue
CLASS Queue
    PRIVATE:
        front: con trỏ Node  // đầu queue
        rear: con trỏ Node   // cuối queue

    PUBLIC:
        // Khởi tạo queue rỗng
        FUNCTION Queue()
            front = NULL
            rear = NULL

        // Thêm phần tử vào cuối queue
        FUNCTION enqueue(x)
            Tạo newNode với data = x
            Nếu rear == NULL  // queue rỗng
                front = rear = newNode
            Ngược lại
                rear->next = newNode
                rear = newNode

        // Xóa phần tử ở đầu queue
        FUNCTION dequeue()
            Nếu front == NULL  // queue rỗng
                return
            temp = front
            front = front->next
            Xóa temp
            Nếu front == NULL  // queue trở thành rỗng
                rear = NULL

        // In queue từ đầu đến cuối
        FUNCTION printQueue()
            temp = front
            Trong khi temp != NULL
                In temp->data + " "
                temp = temp->next
            Xuống dòng

// Chương trình chính
FUNCTION main()
    Đọc n (số lượng thao tác)
    Tạo q là đối tượng Queue

    Lặp n lần:
        Đọc operation
        Nếu operation == "enqueue"
            Đọc x
            q.enqueue(x)
        Ngược lại nếu operation == "dequeue"
            q.dequeue()

    q.printQueue()
    Kết thúc

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr) { 
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            return; 
        }
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr; 
        }
    }

    void printQueue() {
        Node* temp = front;
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
    Queue q; 
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (operation == "dequeue") {
            q.dequeue();
        }
    }
    q.printQueue(); 
    return 0;
}
