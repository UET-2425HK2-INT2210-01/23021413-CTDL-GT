// Enqueue Operation: 
// Time Complexity: O(1)
// Space Complexity: O(1)
function enqueue(queue, data):
    node = new Node(data)       // Create a new node with data
    if queue.rear == null:      // If the queue is empty
        queue.front = node      // Both front and rear point to the new node
        queue.rear = node
    else:
        queue.rear.next = node  // Link the new node to the last node in the queue
        queue.rear = node       // Update the rear pointer to the new node
    end if

// Dequeue Operation
// Time Complexity: O(1)
// Space Complexity: O(1)
function dequeue(queue):
    if queue.front == null:         // If the queue is empty
        return "Queue is empty"     // Return error or empty queue indication
    else:
        front_node = queue.front    // Get the front node
        queue.front = queue.front.next // Move the front pointer to the next node
        if queue.front == null:     // If the queue is now empty
            queue.rear = null       // Reset rear to null
        end if
        return front_node.data      // Return the data of the removed node
    end if

// Peek Operation
// Time Complexity: O(1)
// Space Complexity: O(1) 
function peek(queue):
    if queue.front == null:         // If the queue is empty
        return "Queue is empty"     // Return error or empty queue indication
    else:
        return queue.front.data     // Return the data of the front node
    end if

// Is Empty Operation
// Time Complexity: O(1)
// Space Complexity: O(1)
function isEmpty(queue):
    return queue.front == null     // Return true if front is null, indicating the queue is empty
