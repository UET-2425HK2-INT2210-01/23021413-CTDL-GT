#include <iostream>
using namespace std;

struct Node {
    int data, priority;
    Node* prev;
    Node* next;

    Node(int x, int p) : data(x), priority(p), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}
    void enqueue(int x, int p) {
        Node* newNode = new Node(x, p);
        if (!head || head->priority < p) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->priority >= p) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        if (temp->next) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void dequeue() {
        if (!head) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "(" << temp->data << ", " << temp->priority << ") ";
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }
    void printQueue() {
        Node* temp = head;
        while (temp) {
            cout << "(" << temp->data << ", " << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList queue;
    int n;
    cin >> n;

    while (n--) {
        string command;
        int x, p;
        cin >> command;
        if (command == "enqueue") {
            cin >> x >> p;
            queue.enqueue(x, p);
        }
        else if (command == "dequeue") {
            queue.dequeue();
        }
    }
    queue.printQueue();

    return 0;
}

