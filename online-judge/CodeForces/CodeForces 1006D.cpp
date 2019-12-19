#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string sa, sb;

int main()
{
    int n;
    cin >> n;
    cin >> sa >> sb;
    int ans;
    if ((n & 1) && sa[n / 2] != sb[n / 2])
    {
        ans = 1;
    }
    else
    {
        ans = 0;
    }
    int cnt[500];
    for (int i = 0; i < n / 2; i++)
    {
        memset(cnt, 0, sizeof(cnt));
        int num = 0;
        if (!cnt[sa[i]])
        {
            cnt[sa[i]]++;
            num++;
        }
        if (!cnt[sa[n - i - 1]])
        {
            cnt[sa[n - i - 1]]++;
            num++;
        }
        if (!cnt[sb[i]])
        {
            cnt[sb[i]]++;
            num++;
        }
        if (!cnt[sb[n - i - 1]])
        {
            cnt[sb[n - i - 1]]++;
            num++;
        }
        if (num == 1)
        {
            continue;
        }
        if ((sa[i] == sb[i] && sa[n - i - 1] == sb[n - i - 1]) ||
            (sa[i] == sb[n - i - 1] && sa[n - i - 1] == sb[i]) ||
            (sa[i] == sa[n - i - 1] && sb[i] == sb[n - i - 1]))
        {
            continue;
        }
        if (sa[i] == sb[i] || sa[i] == sb[n - i - 1] || sa[n - i - 1] == sb[i] ||
            sa[n - i - 1] == sb[n - i - 1] || sb[i] == sb[n - i - 1])
        {
            ans++;
        }
        else
        {
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}