#include <iostream>
#include <algorithm>

using namespace std;

int arr[100007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        __int128 mida = 0, midb = n;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            if (arr[i] < 0)
                arr[i] = -arr[i];
            mida += arr[i];
        }
        __int128 suma = 0, sumb = 1;
        for (int i = 1; i <= n; i++)
        {
            __int128 tmpa = arr[i] * midb - mida, tmpb = midb;
            tmpa *= tmpa;
            tmpb *= tmpb;
            suma = suma * tmpb + sumb * tmpa;
            sumb = sumb * tmpb;
            __int128 g = __gcd(suma, sumb);
            suma /= g;
            sumb /= g;
        }
        printf("%lld/%lld\n", (long long)suma, (long long)sumb);
    }
    return 0;
}