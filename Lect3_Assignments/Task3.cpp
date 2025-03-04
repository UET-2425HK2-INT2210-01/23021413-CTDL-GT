// Enqueue
// Time Complexity: O(1)
function enqueue(queue[], front, rear, element, capacity):
    if rear == capacity - 1:
        print "Queue Overflow"  // Check for overflow
    else:
        rear = rear + 1
        queue[rear] = element  // Insert the element at the rear

// Dequeue
// Time Complexity: O(1)
function dequeue(queue[], front, rear):
    if front > rear:
        print "Queue Underflow"  // Check for underflow
    else:
        element = queue[front]
        front = front + 1  // Increment the front pointer to remove the element
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
