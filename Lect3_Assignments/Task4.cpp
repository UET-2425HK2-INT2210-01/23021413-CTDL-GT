4. Your task is to write operations of [Queue] data structure in pseudo-codes using a [Linked List], then evaluate the [Complexities] of the operations.

// Enqueue Operation: 
// Time Complexity: O(1)
// Space Complexity: O(1)
function enqueue(queue, data):
    node = new Node(data)      
    if queue.rear == null:      
        queue.front = node     
        queue.rear = node
    else:
        queue.rear.next = node  
        queue.rear = node      
    end if

// Dequeue Operation
// Time Complexity: O(1)
// Space Complexity: O(1)
function dequeue(queue):
    if queue.front == null:         
        return "Queue is empty"    
    else:
        front_node = queue.front   
        queue.front = queue.front.next 
        if queue.front == null:   
            queue.rear = null       
        end if
        return front_node.data     
    end if

// Peek Operation
// Time Complexity: O(1)
// Space Complexity: O(1) 
function peek(queue):
    if queue.front == null:        
        return "Queue is empty"     
    else:
        return queue.front.data     
    end if

// Is Empty Operation
// Time Complexity: O(1)
// Space Complexity: O(1)
function isEmpty(queue):
    return queue.front == null     
