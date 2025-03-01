#include <iostream>
using namespace std;
double povev (int n) {
    double result = 1;
    if (n < 0) {
        n = n*(-1);
        for (int i = 0; i < n; i++) {
            result *= 2;
        }
        return 1/result;
    } else {
        int result = 1;
        for (int i = 0; i < n; i++) {
            result *= 2;
        }
        return result;
    }
}

int main() {
    int n;
    double result;
    cin >> n;
    cout << povev(n);
    return 0;
}
