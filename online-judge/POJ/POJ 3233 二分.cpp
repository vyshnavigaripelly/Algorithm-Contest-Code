#include <iostream>
#include <cstdio>

using namespace std;

const int N = 35;

int n, mod;

struct Mat
{
    long long mat[N][N];

    friend Mat operator+(const Mat &a, const Mat &b)
    {
        Mat res = {0};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % mod;
        return res;
    }

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
} a, one;

Mat sum(Mat a, int k)
{
    if (k == 1)
        return a;
    Mat b = sum(a, k / 2);
    if (k & 1)
    {
        Mat c = a ^ ((k + 1) / 2);
        return c + b * (c + one);
    }
    else
        return ((a ^ (k / 2)) + one) * b;
}

int main()
{
    int k;
    scanf("%d %d %d", &n, &k, &mod);
    for (int i = 0; i < n; i++)
        one.mat[i][i] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &a.mat[i][j]);
        }
    }
    Mat ans = sum(a, k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lld%c", ans.mat[i][j] % mod, j == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}