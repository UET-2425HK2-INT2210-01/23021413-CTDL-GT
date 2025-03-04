// Algorithm 1: [Time complexity O(n)]
Function calculateTwoPowerIterative(n):
    result = 1  // Start with 1
    for i = 1 to n:
        result = result * 2  // Multiply by 2 each time
    return result
  
// Algorithm 2: [Time complexity O(log n)]
Function calculateTwoPowerEfficient(n):
    result = 1  // Start with 1
    base = 2    // Start with base 2
    while n > 0:
        if n is odd:
            result = result * base  // Multiply result by base if n is odd
        base = base * base   // Square the base
        n = n // 2   // Divide n by 2 (integer division)
    return result
