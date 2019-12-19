#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const short N = 37;

short dp[N][N][N][N], id[N][N][N][N];
short arr[N], brr[N], crr[N], drr[N], val[N];
long long sit[N][N][N][N];
short val_a, val_b, val_c, val_d;

long long fun(long long x, int n)
{
    return x | (1LL << n);
}

int main()
{
    short n;
    cin >> n;
    for (short i = 1; i <= n; i++)
    {
        cin >> arr[i] >> brr[i] >> crr[i] >> drr[i] >> val[i];
    }
    cin >> val_a >> val_b >> val_c >> val_d;
    for (short i = 1; i <= n; i++)
    {
        for (short j = val_a; j >= arr[i]; j--)
        {
            for (short k = val_b; k >= brr[i]; k--)
            {
                for (short l = val_c; l >= crr[i]; l--)
                {
                    for (short m = val_d; m >= drr[i]; m--)
                    {
                        if (dp[j][k][l][m] < dp[j - arr[i]][k - brr[i]][l - crr[i]][m - drr[i]] + val[i])
                        {
                            dp[j][k][l][m] = dp[j - arr[i]][k - brr[i]][l - crr[i]][m - drr[i]] + val[i];
                            long long now = sit[j - arr[i]][k - brr[i]][l - crr[i]][m - drr[i]];
                            long long next = fun(now, i);
                            sit[j][k][l][m] = next;
                        }
                    }
                }
            }
        }
    }
    short ans = 0, cnt = 0;
    vector<int> mmp;
    long long fin;
    for (short i = 0; i <= val_a; i++)
    {
        for (short j = 0; j <= val_b; j++)
        {
            for (short k = 0; k <= val_c; k++)
            {
                for (short l = 0; l <= val_d; l++)
                {
                    if (ans < dp[i][j][k][l])
                    {
                        ans = dp[i][j][k][l];
                        fin = sit[i][j][k][l];
                    }
                }
            }
        }
    }
    int now = 1;
    while (ans && now < 40)
    {
        if (fin >> now & 1)
        {
            mmp.push_back(now - 1);
        }
        now++;
    }
    cout << mmp.size() << endl;
    for (int i = 0; i < mmp.size(); i++)
    {
        cout << mmp[i] << " ";
    }
    return 0;
}