6. Your task is to write operations of stack data structure in pseudo-codes using a linked list, then evaluate the complexities of the operations.
// Stack Node Structure: 
struct Node 
    int data;
    Node* next

// Push Operation: Time Complexity: O(1)
function push(Node*& top, int value) 
    Node* newNode = new Node()
    newNode->data = value
    newNode->next = top  
    top = newNode  


// Pop Operation: Time Complexity: O(1)
function pop(Node*& top) 
    if (top == nullptr) 
        throw "Stack Underflow"  
    Node* temp = top;
    int value = top->data
    top = top->next  
    delete temp  
    return value


// Peek Operation: Time Complexity: O(1)
function peek(Node* top) 
    if (top == nullptr) 
        throw "Stack Underflow"  
    return top->data  

// IsEmpty Operation: Time Complexity: O(1)
function isEmpty(Node* top) 
    return top == nullptr  

// Size Operation: Time Complexity: O(n)
function size(Node* top) 
    int count = 0;
    Node* current = top
    while (current != nullptr) 
        count++
        current = current->next

    return count;  



