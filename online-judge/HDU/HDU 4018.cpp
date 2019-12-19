#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        char s[100];
        scanf("%*[^:]://%[^:/]%*s", s);
        printf("Case #%d: %s\n", cas, s);
    }
    return 0;
}
