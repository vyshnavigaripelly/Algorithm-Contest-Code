#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += (a[i] == b[i]);
        }
        if (cnt + n >= x + y && abs(x - y) <= n - cnt)
        {
            cout << "Not lying" << endl;
        }
        else
        {
            cout << "Lying" << endl;
        }
    }
    return 0;
}