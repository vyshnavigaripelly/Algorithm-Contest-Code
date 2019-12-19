#include <iostream>
#include <map>

using namespace std;

const int N = 1e5 + 7;

int arr[N];
long long sum[N];
map<long long, int> rk;

int main()
{
    int n, m, c;
    while (~scanf("%d%d%d", &n, &m, &c))
    {
        rk.clear();
        rk[0]++;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            sum[i] = sum[i - 1] + arr[i];
            rk[sum[i]]++;
        }
        long long ans = 0;
        while (rk.size() > 1 && m)
        {
            auto i = rk.end(), j = rk.begin();
            i--;
            long long res = i->first - j->first - c;
            if (res < 0)
            {
                break;
            }
            ans += res;
            m--;
            i->second--;
            j->second--;
            if (i->second == 0)
            {
                rk.erase(i);
            }
            if (j->second == 0)
            {
                rk.erase(j);
            }
        }
        cout << ans << endl;
    }
    return 0;
}