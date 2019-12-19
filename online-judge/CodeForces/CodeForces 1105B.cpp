#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[26];

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cur = 0;
    char last = s[0];
    s += '0';
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != last)
        {
            arr[last - 'a'].push_back(i - 1 - cur + 1);
            last = s[i];
            cur = i;
        }
    }
    int ans = 0;
    for (auto i : arr)
    {
        int tmp = 0;
        for (auto j : i)
        {
            tmp += j / k;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}