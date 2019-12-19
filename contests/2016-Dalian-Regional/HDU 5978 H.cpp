#include <iostream>
using namespace std;

int main()
{
    int k;
    while (cin >> k)
    {
        if (k % 2 == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}