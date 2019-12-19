#include <iostream>

using namespace std;

int arr[30];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr[s[0] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        int tmp = arr[i] / 2;
        ans += max(0, tmp * (tmp - 1) / 2);
        ans += max(0, (arr[i] - tmp) * (arr[i] - tmp - 1) / 2);
    }
    cout << ans << endl;
    return 0;
}