#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, b, flag = 0;
        cin >> n >> b;
        while (n--)
        {
            int a;
            cin >> a;
            if ((a + b) % 7 == 0)
            {
                flag = 1;
            }
        }
        if (flag)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
