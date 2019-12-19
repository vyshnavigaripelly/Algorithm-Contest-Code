#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

int ans[1007];

int check(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return 0;
    }

    int temp = x % 10;
    int temp2 = (x / 10) % 10;
    int temp3 = x / 100 % 10;
    int temp4 = x / 1000;

    int ans1 = temp2 * 10 + temp;
    int ans2 = temp3 * 10 + temp;
    int ans5 = temp4 * 10 + temp;

    int ans8 = temp3 * 10 + temp2;
    int ans9 = temp4 * 10 + temp2;
    int ans10 = temp4 * 10 + temp3;

    int ans6 = temp3 * 100 + temp2 * 10 + temp;
    int ans7 = temp4 * 100 + temp2 * 10 + temp;
    int ans3 = temp4 * 100 + temp3 * 10 + temp2;

    for (int i = 2; i <= sqrt(temp); i++)
    {
        if (temp % i == 0)
            return 0;
    }
    for (int i = 2; i <= sqrt(temp2); i++)
    {
        if (temp2 % i == 0)
            return 0;
    }
    for (int i = 2; i <= sqrt(temp3); i++)
    {
        if (temp3 % i == 0)
            return 0;
    }
    for (int i = 2; i <= sqrt(ans1); i++)
    {
        if (ans1 % i == 0)
            return 0;
    }
    for (int i = 2; i <= sqrt(ans2); i++)
    {
        if (ans2 % i == 0)
            return 0;
    }
    for (int i = 2; i <= sqrt(ans3); i++)
    {
        if (ans3 % i == 0)
            return 0;
    }
    for (int i = 2; i <= sqrt(ans5); i++)
    {
        if (ans5 % i == 0)
            return 0;
    }
    for (int i = 2; i <= sqrt(ans6); i++)
    {
        if (ans6 % i == 0)
            return 0;
    }
    for (int i = 2; i <= sqrt(ans7); i++)
    {
        if (ans7 % i == 0)
            return 0;
    }
    for (int i = 2; i <= sqrt(ans8); i++)
    {
        if (ans8 % i == 0)
            return 0;
    }
    for (int i = 2; i <= sqrt(ans9); i++)
    {
        if (ans9 % i == 0)
            return 0;
    }
    for (int i = 2; i <= sqrt(ans10); i++)
    {
        if (ans10 % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    for (int i = 2; i <= 999; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            if (check(j))
            {
                ans[i] = j;
            }
        }
    }
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        char n[107];
        cin >> n;
        cout << "Case #" << cas << ": ";
        if (strlen(n) >= 4)
        {
            cout << 317 << endl;
        }
        else
        {
            int k = atoi(n);
            cout << ans[k] << endl;
        }
    }
    return 0;
}
