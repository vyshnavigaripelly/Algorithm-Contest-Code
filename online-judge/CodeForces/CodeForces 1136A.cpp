#include <iostream>

using namespace std;

int l[1007], r[1007];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        if (m >= l[i] && m <= r[i])
        {
            cout << n - i << endl;
            break;
        }
    }
    return 0;
}