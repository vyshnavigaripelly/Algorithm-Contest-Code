#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k;
    cin >> k;
    cout << (k <= 36 ? (string(k / 2, '8') + string(k % 2, '6')) : "-1") << endl;
    return 0;
}
