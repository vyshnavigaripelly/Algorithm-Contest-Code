#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long arr[200007];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    string s;
    cin >> s;
    long long ans = 0;
    for (int i = 0; i < n;)
    {
        int j = i;
        vector<long long> tmp;
        while (j < n && s[i] == s[j])
        {
            tmp.push_back(arr[j]);
            j++;
        }
        sort(tmp.begin(), tmp.end(), greater<long long>());
        ans += accumulate(tmp.begin(), tmp.begin() + min(k, (int)tmp.size()), 0LL);
        i = j;
    }
    cout << ans << endl;
    return 0;
}