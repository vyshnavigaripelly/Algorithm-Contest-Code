#include <iostream>
#include <cstdio>

using namespace std;

int a, b;
int ansa = 6, ansb = 5;

int ask(int c, int d)
{
    printf("? %d %d\n", c, d);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main()
{
    int abig = ask(0, 0); // 1 if a > b else -1
    for (int i = 29; i >= 0; i--)
    {
        int fi = ask(a ^ (1 << i), b), se = ask(a, b ^ (1 << i));
        if (fi == se) // different bit
        {
            if (abig == 1)
            {
                a ^= (1 << i);
            }
            else
            {
                b ^= (1 << i);
            }
            abig = fi;
        }
        else if (se == 1) // same bit, 1
        {
            a ^= (1 << i);
            b ^= (1 << i);
        }
    }
    printf("! %d %d\n", a, b);
    return 0;
}