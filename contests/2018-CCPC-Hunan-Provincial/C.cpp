#include <iostream>

using namespace std;

int main()
{
    long long h, c;
    while (~scanf("%lld %lld", &h, &c))
    {
        printf("%lld\n", max(h, c + 1));
    }
    return 0;
}