#include <iostream>
#include <map>

using namespace std;

int s[107], d[107];

int main()
{
    int n, t;
    cin >> n >> t;
    pair<int, int> ans = {1e9, -1};
    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> d[i];
        while (s[i] < t)
        {
            s[i] += d[i];
        }
        ans = min(ans, {s[i], i});
    }
    cout << ans.second + 1 << endl;
    return 0;
}