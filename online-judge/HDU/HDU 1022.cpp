#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        int a[10] = {0}, b[10] = {0};
        for (int i = 0; i < n; i++)
        {
            scanf("%1d", &a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%1d", &b[i]);
        }
        int pA = 0, pB = 0;
        stack<int> s;
        queue<char> op;
        while (pB < n && pA <= n)
        {
            if (!s.empty() && b[pB] == s.top())
            {
                pB++;
                s.pop();
                op.push('O');
            }
            else if (pA <= n)
            {
                s.push(a[pA]);
                pA++;
                op.push('I');
            }
            else
            {
                break;
            }
        }
        if (pB == n)
        {
            printf("Yes.\n");
            while (!op.empty())
            {
                if (op.front() == 'I')
                {
                    printf("in\n");
                }
                else
                {
                    printf("out\n");
                }
                op.pop();
            }
            printf("FINISH\n");
        }
        else
        {
            printf("No.\nFINISH\n");
        }
    }
    return 0;
}
