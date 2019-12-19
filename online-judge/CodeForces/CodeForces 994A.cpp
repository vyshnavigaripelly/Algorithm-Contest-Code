#include <iostream>
using namespace std;

int main()
{
    int n, m, a[15], b[15];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                cout << a[i] << ' ';
            }
        }
    }
    cout << endl;
    return 0;
}