#include <iostream>

using namespace std;

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", max(40 + y * 2, 39 + x * 2));
    return 0;
}