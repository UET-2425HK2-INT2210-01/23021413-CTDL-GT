3. Your task is to write operations of [Queue] data structure in pseudo-codes using an [Array], then evaluate the [Complexities] of the operations.
// Enqueue
// Time Complexity: O(1)
function enqueue(queue[], front, rear, element, capacity):
    if rear == capacity - 1:
        print "Queue Overflow"  
    else:
        rear = rear + 1
        queue[rear] = element  

// Dequeue
// Time Complexity: O(1)
function dequeue(queue[], front, rear):
    if front > rear:
        print "Queue Underflow"  
    else:
        element = queue[front]
        front = front + 1  
        return element
    
// Front
// Time Complexity: O(1)
function front(queue[], front, rear):
    if front > rear:
        print "Queue is empty"
    else:
        return queue[front]
    
// IsEmpty
// Time Complexity: O(1)
function isEmpty(front, rear):
    return front > rear
    
// IsFull
// Time Complexity: O(1)
function isFull(rear, capacity):
    return rear == capacity - 1
    
// Size
// Time Complexity: O(1)
function size(front, rear):
    return rear - front + 1
