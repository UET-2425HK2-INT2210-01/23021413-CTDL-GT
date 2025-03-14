#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() : head(nullptr) {}
    void append(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void search(int x) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == x) {
                cout << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "NO" << endl;
    }
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n;
    cin >> n;
    while (n--) {
        string command;
        int x;
        cin >> command;
        if (command == "append") {
            cin >> x;
            list.append(x);
        }
        else if (command == "search") {
            cin >> x;
            list.search(x);
        }
        else if (command == "reverse") {
            list.reverse();
        }
    }
    list.printList();
    return 0;
}

