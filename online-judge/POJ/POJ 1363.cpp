#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    int n, b[1100];
    while (~scanf("%d", &n) && n)
    {
        int pA, pB;

        while (~scanf("%d", &b[0]) && b[0])
        {
            stack<int> s;
            for (int i = 1; i < n; i++)
            {
                scanf("%d", &b[i]);
            }
            pA = 1;
            pB = 0;
            while (pB < n && pA <= n + 1)
            {
                if (!s.empty() && b[pB] == s.top())
                {
                    pB++;
                    s.pop();
                }
                else if (pA <= n)
                {
                    s.push(pA);
                    pA++;
                }
                else
                {
                    break;
                }
            }
            if (pB == n)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        printf("\n");
    }
    return 0;
}
