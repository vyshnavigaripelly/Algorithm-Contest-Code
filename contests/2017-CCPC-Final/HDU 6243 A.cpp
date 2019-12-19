#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %.8f\n", cas, 1.0 * (n - 1));
    }
    return 0;
}