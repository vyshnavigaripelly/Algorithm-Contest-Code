#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        puts(n == 1 ? "18000" : "0");
    }
    return 0;
}