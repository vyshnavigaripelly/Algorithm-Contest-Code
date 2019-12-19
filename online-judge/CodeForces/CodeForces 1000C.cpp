#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct Point
{
    long long pos;
    bool start;
} arr[412345];

long long ans[212345];

int main()
{
    int n;
    cin >> n;
    map<long long, int> cnt;
    for (int i = 0; i < n; i++)
    {
        long long start, end;
        cin >> start >> end;
        cnt[start]++;
        cnt[end + 1]--;
    }
    long long num = 0, last;
    for (auto it = cnt.begin(); it != cnt.end(); it++)
    {
        if (it == cnt.begin())
        {
            last = it->first;
            num = it->second;
            continue;
        }
        ans[num] += it->first - last;
        last = it->first;
        num += it->second;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}
