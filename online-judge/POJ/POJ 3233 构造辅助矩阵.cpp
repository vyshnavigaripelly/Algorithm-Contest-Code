#include <iostream>
#include <cstdio>

using namespace std;

const int N = 35;

int n, mod;

struct Mat
{
    long long mat[N * 2][N * 2];

    friend Mat operator*(const Mat &a, const Mat &b)
    {
        Mat res = {0};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    res.mat[i][j] = (res.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % mod;
        return res;
    }

    friend Mat operator^(Mat a, long long k)
    {
        Mat res = {0};
        for (int i = 0; i < n; i++)
            res.mat[i][i] = 1;
        while (k)
        {
            if (k & 1)
                res = res * a;
            k >>= 1;
            a = a * a;
        }
        return res;
    }
};

int main()
{
    int k;
    scanf("%d %d %d", &n, &k, &mod);
    Mat a = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &a.mat[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        a.mat[i][i + n] = a.mat[i + n][i + n] = 1;
    }
    n *= 2;
    Mat ans = a ^ (k + 1);
    n /= 2;
    for (int i = 0; i < n; i++)
    {
        ans.mat[i][i + n] = (ans.mat[i][i + n] - 1 + mod) % mod;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lld%c", ans.mat[i][j + n], j == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}