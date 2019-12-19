#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string a;
    cin >> a;
    string b = a;
    reverse(a.begin(), a.end());
    cout << a + b << endl;
    return 0;
}
