#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100007];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> cnt;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n && arr[i] == arr[j])
        {
            j++;
        }
        cnt.push_back(j - i);
        i = j - 1;
    }
    int ans = 0;
    for (int i = 0; i < cnt.size() - 1; i++)
    {
        ans = max(ans, min(cnt[i], cnt[i + 1]));
    }
    cout << ans * 2 << endl;
    return 0;
}