#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    puts(n % 2 == 0 && n > 0 ? "qiandaochenggong" : "qiandaoshibai");
    return 0;
}