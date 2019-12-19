#include <iostream>

using namespace std;

int arr[300007], brr[300007];
int cnt[3];

string s;

int main()
{
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        cnt[s[i] - '0']++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (cnt[0] < n / 3 && s[i] > '0' && cnt[s[i] - '0'] > n / 3)
        {
            cnt[0]++;
            cnt[s[i] - '0']--;
            s[i] = '0';
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (cnt[1] < n / 3 && s[i] > '1' && cnt[s[i] - '0'] > n / 3)
        {
            cnt[1]++;
            cnt[s[i] - '0']--;
            s[i] = '1';
        }
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (cnt[2] < n / 3 && s[i] < '2' && cnt[s[i] - '0'] > n / 3)
        {
            cnt[2]++;
            cnt[s[i] - '0']--;
            s[i] = '2';
        }
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (cnt[1] < n / 3 && s[i] < '1' && cnt[s[i] - '0'] > n / 3)
        {
            cnt[1]++;
            cnt[s[i] - '0']--;
            s[i] = '1';
        }
    }
    cout << s << endl;
    return 0;
}