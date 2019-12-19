#include <iostream>
#include <algorithm>
using namespace std;

int s[1000];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        sort(s, s + n);
        for (int i = 0; i < n; i++)
        {
            cout << s[i];
            if (i != n - 1)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
    }
    return 0;
}
