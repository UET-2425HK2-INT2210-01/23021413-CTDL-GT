5. Your task is to write operations of stack data structure in pseudo-codes using an array, then evaluate the complexities of the operations.

// Push Operation: Time Complexity: O(1)
function push(stack, top, item):
    if top == stack.size - 1:  # Stack is full
        print("Stack Overflow")
    else:
        top = top + 1
        stack[top] = item
    return top
  
// Pop Operation: Time Complexity: O(1)
function pop(stack, top):
    if top == -1:  # Stack is empty
        print("Stack Underflow")
        return None
    else:
        item = stack[top]
        top = top - 1
        return item, top

// Peek Operation: Time Complexity: O(1)
function peek(stack, top):
    if top == -1:
        print("Stack is Empty")
        return None
    else:
        return stack[top]
          
// isEmpty Operation: Time Complexity: O(1)
function isEmpty(top):
    return top == -1
  
// isFull Operation: Time Complexity: O(1)
function isFull(top, stack_size):
    return top == stack_size - 1

// Display Operation: Time Complexity: O(n)
function display(stack, top):
    if top == -1:
        print("Stack is Empty")
    else:
        for i from 0 to top:
            print(stack[i])
