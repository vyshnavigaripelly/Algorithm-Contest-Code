#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int num[4] = {1, 5, 10, 50};
int now[15];
set<int> se;

void dfs(int step, int n)
{
    if (step == n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += now[i];
        }
        se.insert(sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        now[step] = num[i];
        dfs(step + 1, n);
    }
}

int main()
{
    // for (int i = 0; i < 15; i++)
    // {
    //     memset(now, 0, sizeof(now));
    //     se.clear();
    //     dfs(0, i);
    //     cout << se.size() << ", ";
    // }
    int ans[] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341, 390};
    int n;
    cin >> n;
    if (n < 12)
    {
        cout << ans[n] << endl;
    }
    else
    {
        cout << ans[12] + 1LL * (n - 12) * 49 << endl;
    }
    return 0;
}