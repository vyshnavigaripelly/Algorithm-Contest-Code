#include <iostream>

using namespace std;

const int N = 2001;
const int mod = 1e9 + 7;

int f[N][N];

int main()
{
    for (int i = 1; i < N; i++)
    {
        f[i][1] = f[1][i] = i;
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (i == 1 || j == 1)
                continue;
            f[i][j] = (1LL + f[i - 1][j] + f[i][j - 1]) % mod;
        }
    }
    int n, m;
    while (~scanf("%d %d", &n, &m))
    {
        printf("%lld\n", 1LL * f[n][m] * f[n][m] % mod);
    }
    return 0;
}