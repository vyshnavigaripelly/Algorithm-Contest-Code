#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a, b, c, d;
    scanf("%d:%d", &a, &b);
    scanf("%d:%d", &c, &d);
    int mid = ((a * 60 + b) + (c * 60 + d)) / 2;
    printf("%02d:%02d", mid / 60, mid % 60);
    return 0;
}