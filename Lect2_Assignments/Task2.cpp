// 2. The linked list structure has two following operations:
// − insert (p, x): insert an integer number x at position p, elements from
//                  p are moved backward one position.
// − delete (p): delete element at position p, elements after p are moved
//               forward one position.
// Start from an empty list, your task is to implement a linked list, perform
// operations read from the keyboard.
//    Input:
//    − The first line contains an integer number n which is the number of
//      operations.
//    − The next n lines contain the operation description. One operation is
//      in one line in either format:
//      ● insert p x
//      ● delete p
// where p is the position and x is the number.
//    Output: Write the resulting linked list to the screen in one line. Numbers
//            are separated by spaces.

// Example
// Keyboard          Screen
// 5                 1 2 3
// insert 0 1
// insert 1 3
// insert 1 4
// insert 2 2
// delete 1

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    private:
        Node* head;
    public:
        LinkedList() : head(nullptr) {}
        
        void insert(int p, int x) {
            Node* newNode = new Node(x);

            if (p == 0) {
                newNode->next = head;
                head = newNode;
            } else {
                Node* temp = head;
                for (int i = 0; i < p - 1 && temp != nullptr; i++) {
                    temp = temp->next;
                }
                if (temp != nullptr) {
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
            }
        }

        void deleteNode(int p) {
            if (head == nullptr) return;

            if (p == 0) {
                Node* temp = head;
                head = head->next;
                delete temp;
            } else {
                Node* temp = head;
                for (int i = 0; i < p - 1 && temp != nullptr; i++) {
                    temp = temp->next;
                }
                if (temp != nullptr && temp->next != nullptr) {
                    Node* delNode = temp->next;
                    temp->next = temp->next->next;
                    delete delNode;
                }
            }
        }

        void printList() {
            Node* temp = head;
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
    LinkedList list;
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int p, x;
            cin >> p >> x;
            list.insert(p, x);
        } else if (operation == "delete") {
            int p;
            cin >> p;
            list.deleteNode(p);
        }
    }
    list.printList();
    return 0;
}
