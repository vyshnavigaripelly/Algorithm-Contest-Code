#include <iostream>
#include <cstdio>

using namespace std;

long long arr[100007], bmul[100007] = {1};

int main()
{
    int b, k;
    scanf("%d %d", &b, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%lld", &arr[i]);
    }
    for (int i = 1; i < k; i++)
    {
        bmul[i] = bmul[i - 1] * b % 10;
    }
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans = (ans + (arr[i] % 10 * bmul[k - 1 - i] % 10)) % 10;
    }
    puts(ans % 2 == 0 ? "even" : "odd");
    return 0;
}