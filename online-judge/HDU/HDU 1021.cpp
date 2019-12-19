#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        cout << (((n - 2) % 4 == 0) ? "yes" : "no") << endl;
    }
    return 0;
}
