#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n; 
    vector<int> A(n); 
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if (A[i] == A[j]) {
                count++;
            }
        }
    }
    cout << count << endl; 
    return 0;
}

