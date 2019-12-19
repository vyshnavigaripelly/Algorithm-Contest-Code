#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    printf("%.3f\n", 1.0 * n * n / 2 / acos(-1.0));
    return 0;
}