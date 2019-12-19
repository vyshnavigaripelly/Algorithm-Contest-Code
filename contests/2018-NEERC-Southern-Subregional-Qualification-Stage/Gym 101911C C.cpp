#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

unordered_map<long long, int> bit;
priority_queue<long long, vector<long long>, greater<long long>> q;

int main()
{
    long long num = 1;
    int cnt = 0;
    while (num <= (long long)1e18)
    {
        bit[num] = cnt;
        cnt++;
        num *= 2;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        scanf("%lld", &tmp);
        q.push(tmp);
    }
    long long ans = 0;
    while (q.size() > 1)
    {
        long long first = q.top();
        q.pop();
        long long second = q.top();
        q.pop();
        if ((second % first == 0) && bit.count(second / first))
        {
            ans += bit[second / first];
            q.push(second * 2);
        }
        else
        {
            puts("-1");
            return 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}