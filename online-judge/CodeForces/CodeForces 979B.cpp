#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

int cnta[52], cntb[52], cntc[52], len, n;

int change(int k)
{
    if (k < len)
    {
        if (k + n >= len)
        {
            return len;
        }
        else
        {
            return k + n;
        }
    }
    else if (k == len)
    {
        if (n == 1)
        {
            return len - 1;
        }
        else
        {
            return len;
        }
    }
    else
    {
        return k;
    }
}

int main()
{
    string a, b, c;
    cin >> n >> a >> b >> c;
    int aa, bb, cc;
    len = a.length();
    for (int i = 0; i < len; i++)
    {
        cnta[isupper(a[i]) ? a[i] - 'A' : a[i] - 'a' + 26]++;
        cntb[isupper(b[i]) ? b[i] - 'A' : b[i] - 'a' + 26]++;
        cntc[isupper(c[i]) ? c[i] - 'A' : c[i] - 'a' + 26]++;
    }
    sort(cnta, cnta + 52, greater<int>());
    sort(cntb, cntb + 52, greater<int>());
    sort(cntc, cntc + 52, greater<int>());
    aa = change(cnta[0]);
    bb = change(cntb[0]);
    cc = change(cntc[0]);
    int ans[3] = {aa, bb, cc};
    string name[3] = {"Kuro", "Shiro", "Katie"};
    string ansname = name[max_element(ans, ans + 3) - ans];
    sort(ans, ans + 3, greater<int>());
    if (ans[0] == ans[1])
    {
        cout << "Draw" << endl;
    }
    else
    {
        cout << ansname << endl;
    }
    return 0;
}
