#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 1e5 + 7, mod = 1e5 - 9;

struct Snow
{
    int a[6];
};

Snow arr[N];
vector<Snow> hsh[N];

int H(int pos)
{
    long long sum = 0, mul = 1;
    for (int i = 0; i < 6; i++)
    {
        sum = (sum + arr[pos].a[i]) % mod;
        mul = (mul * arr[pos].a[i]) % mod;
    }
    return (sum + mul) % mod;
}

int check(int pa, int h, int pb)
{
    Snow a = arr[pa], b = hsh[h][pb];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int flag1 = 1, flag2 = 1;
            for (int k = 0; k < 6 && flag1; k++)
            {
                if (a.a[(i + k) % 6] != b.a[(j + k) % 6])
                {
                    flag1 = 0;
                }
            }
            if (flag1)
            {
                return 1;
            }
            for (int k = 0; k < 6 && flag2; k++)
            {
                if (a.a[(i + k) % 6] != b.a[(j - k + 6) % 6])
                {
                    flag2 = 0;
                }
            }
            if (flag2)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &arr[i].a[j]);
        }
        int ha = H(i);
        if (!hsh[ha].empty())
        {
            for (int k = 0; k < hsh[ha].size(); k++)
            {
                if (check(i, ha, k))
                {
                    puts("Twin snowflakes found.");
                    return 0;
                }
            }
        }
        hsh[ha].push_back(arr[i]);
    }
    puts("No two snowflakes are alike.");
    return 0;
}