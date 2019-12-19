#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int s = 1;
        for (int i = 1; i < n; i++)
        {
            s <<= 1;
            s %= 1000000009;
        }
        cout << s << endl;
    }
    return 0;
}
