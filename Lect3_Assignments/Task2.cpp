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
