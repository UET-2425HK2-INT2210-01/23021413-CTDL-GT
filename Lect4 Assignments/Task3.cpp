#include <iostream>
#include <stack>
using namespace std;

bool isValid(const string& s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } 
        else if (c == ')' || c == ']' || c == '}') {
            if (stk.empty()) {
                return false; 
            }
            char top = stk.top();
            if ((c == ')' && top == '(') || 
                (c == ']' && top == '[') || 
                (c == '}' && top == '{')) {
                stk.pop(); 
            } else {
                return false; 
            }
        }
    }
    return stk.empty(); 
}

int main() {
    string input;
    cin >> input;
    
    if (isValid(input)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
    
    return 0;
}

