// Stack Node Structure: 
struct Node {
    int data;
    Node* next;
};

// Push Operation: Time Complexity: O(1)
function push(Node*& top, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;  // Point to the current top node
    top = newNode;  // Update the top to the new node
}

// Pop Operation: Time Complexity: O(1)
function pop(Node*& top) {
    if (top == nullptr) {
        throw "Stack Underflow";  // Error if the stack is empty
    }
    Node* temp = top;
    int value = top->data;
    top = top->next;  // Update top to the next node
    delete temp;  // Free the memory of the popped node
    return value;
}

// Peek Operation: Time Complexity: O(1)
function peek(Node* top) {
    if (top == nullptr) {
        throw "Stack Underflow";  // Error if the stack is empty
    }
    return top->data;  // Return the value of the top node
}

// IsEmpty Operation: Time Complexity: O(1)
function isEmpty(Node* top) {
    return top == nullptr;  // Return true if the stack is empty
}

// Size Operation: Time Complexity: O(n)
function size(Node* top) {
    int count = 0;
    Node* current = top;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;  // Return the number of elements in the stack
}


