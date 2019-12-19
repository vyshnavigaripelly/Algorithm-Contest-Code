#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

bool notprime[MAXN];
int sum[MAXN];

void init()
{
    memset(notprime, false, sizeof(notprime));
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < MAXN; i++)
        if (!notprime[i])
        {
            if (i > MAXN / i)
                continue;
            for (int j = i * i; j < MAXN; j += i)
                notprime[j] = true;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    for (int i = 1; i < MAXN; i++)
    {
        sum[i] = sum[i - 1] + (notprime[i] == false);
    }
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << sum[n] << endl;
    }
    return 0;
}