#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int f = 1;
    while (n--)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            f = 0;
        }
    }
    if (f)
    {
        cout << "easy" << endl;
    }
    else
    {
        cout << "hard" << endl;
    }
    return 0;
}