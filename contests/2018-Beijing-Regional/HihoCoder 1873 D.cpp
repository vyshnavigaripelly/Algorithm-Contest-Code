#include <iostream>
#include <cstring>
using namespace std;

int f[207];

int main()
{
    long long n;
    while (cin >> n)
    {
        int sum = 0;
        memset(f, 0, sizeof(f));
        for (int i = 0; i < 32; i++)
        {
            int ans = n >> i & 1;
            if (i == 0)
            {
                if (ans)
                    f[1] = 199;
                else
                    f[1] = 1;
            }
            else
            {
                if (ans)
                {
                    int tmp = 6 * i + 1;
                    //int next = 6 * (i + 1) + 1;
                    f[tmp] = 199;
                    f[tmp - 1] = 199;
                    f[tmp - 3] = tmp + 1;
                }
                else
                {
                    int tmp = 6 * i + 1;
                    //int next = 6 * (i + 1) + 1;
                    f[tmp] = tmp;
                    f[tmp - 1] = tmp - 1;
                    f[tmp - 3] = tmp + 1;
                }
            }
        }
        for (int i = 6 * 32 + 1; i <= 198; i++)
            f[i] = i;
        if (n == 0)
            f[1] = 1, f[2] = 2;
        for (int i = 1; i <= 198; i++)
        {
            if (f[i])
            {
                sum++;
            }
        }
        cout << sum << endl;
        for (int i = 1; i <= 198; i++)
        {
            if (f[i])
                cout << i << " " << f[i] << endl;
        }
    }
    return 0;
}