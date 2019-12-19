#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

struct Mat
{
    long long ma[3][3];
    // Mat() { memset(ma, 0, sizeof(ma)); }
};

Mat matmul(Mat x, Mat y)
{
    Mat res = {0};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                res.ma[i][j] = (res.ma[i][j] + x.ma[i][k] * y.ma[k][j]) % mod;
    return res;
}

Mat matpow(Mat a, long long n)
{
    Mat res = {0};
    for (int i = 0; i < 3; i++)
    {
        res.ma[i][i] = 1;
    }
    while (n)
    {
        if (n & 1)
            res = matmul(res, a);
        n >>= 1;
        a = matmul(a, a);
    }
    return res;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long a, b, c, d, p, n;
        scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &p, &n);
        if (n == 1)
        {
            printf("%lld\n", a);
            continue;
        }
        if (n == 2)
        {
            printf("%lld\n", b);
            continue;
        }
        // + D  C  p/n +   + F(n-1) +   +  F(n)  +
        // | 1  0   0  | * | F(n-2) | = | F(n-1) +
        // + 0  0   1  +   +   1    +   +   1    +
        Mat m = {{{d, c, 0}, {1, 0, 0}, {0, 0, 1}}};
        long long now = 3;
        int flag = 1;
        while (now <= n)
        {
            if (p / now == 0)
            {
                Mat tmp = matpow(m, n - now + 1);
                long long ans = (tmp.ma[0][0] * b + tmp.ma[0][1] * a + tmp.ma[0][2]) % mod;
                printf("%lld\n", ans);
                flag = 0;
                break;
            }
            else
            {
                long long r = min(n, p / (p / now));
                Mat tmp = {{{d, c, p / now}, {1, 0, 0}, {0, 0, 1}}};
                tmp = matpow(tmp, r - now + 1);
                long long A = (tmp.ma[1][0] * b + tmp.ma[1][1] * a + tmp.ma[1][2]) % mod;
                long long B = (tmp.ma[0][0] * b + tmp.ma[0][1] * a + tmp.ma[0][2]) % mod;
                a = A;
                b = B;
                now = r + 1;
            }
        }
        if (flag)
        {
            printf("%lld\n", b);
        }
    }
    return 0;
}