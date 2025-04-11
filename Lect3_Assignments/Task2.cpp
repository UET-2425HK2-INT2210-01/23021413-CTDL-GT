2. Given an integer number n, your task is to write two different algorithms in pseudo-codes to calculate 2^n, and evaluate the complexity of the algorithms.

// Algorithm 1: [Time complexity O(n)]
Function calculateTwoPowerIterative(n):
    result = 1  
    for i = 1 to n:
        result = result * 2  
    return result
  
// Algorithm 2: [Time complexity O(log n)]
Function calculateTwoPowerEfficient(n):
    result = 1  
    base = 2    
    while n > 0:
        if n is odd:
            result = result * base  
        base = base * base   
        n = n 
    return result
