#include <iostream>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int l = str.length();

    for (int i = 0; i < l/2; i++) {
        swap(str[i], str[l - i - 1]);
    }
    cout << str << endl;
    return 0;
}
