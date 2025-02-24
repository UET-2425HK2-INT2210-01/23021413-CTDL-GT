#include <iostream>
using namespace std;

int main() {
    double num1, num2, num3, num4, num5;
    cin >> num1 >> num2 >> num3 >> num4 >> num5;
    double smallest = num1, largest = num1;
    if (num2 < smallest) smallest = num2;
    if (num2 > largest) largest = num2;
    if (num3 < smallest) smallest = num3;
    if (num3 > largest) largest = num3;
    if (num4 < smallest) smallest = num4;
    if (num4 > largest) largest = num4;
    if (num5 < smallest) smallest = num5;
    if (num5 > largest) largest = num5;
    cout << smallest + largest << endl;
    return 0;
}
