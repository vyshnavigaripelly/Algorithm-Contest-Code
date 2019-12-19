#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cnt[1007];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s >> t;
    string tmp = s;
    int l = s.find(t), cut = 0;
    while (l != string::npos)
    {
        l += cut;
        cnt[l + m - 1] = 1;
        l++;
        tmp = string(s, l);
        cut = l;
        l = tmp.find(t);
    }
    for (int i = 1; i < n; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int start = a - 1, end = b - 1;
        if (end - start + 1 < m)
        {
            cout << 0 << endl;
        }
        else if (end - start + 1 == m)
        {
            if (string(s, start, m) == t)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else
        {
            cout << cnt[end] - ((start - 1 + m - 1 == -1) ? 0 : cnt[start - 1 + m - 1]) << endl;
        }
    }
    return 0;
}