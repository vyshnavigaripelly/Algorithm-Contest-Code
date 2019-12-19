#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

queue<int> s1, s2, s3, s4, s5;
char s[200007];

int main()
{
    int n;
    while (~scanf("%d %s", &n, s))
    {
        while (!s1.empty())
            s1.pop();
        while (!s2.empty())
            s2.pop();
        while (!s3.empty())
            s3.pop();
        while (!s4.empty())
            s4.pop();
        while (!s5.empty())
            s5.pop();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'x')
                s1.push(i);
            else if (s[i] == 't')
                s2.push(i);
            else if (s[i] == 'C')
                s3.push(i);
            else if (s[i] == 'p')
                s4.push(i);
            else if (s[i] == 'c')
                s5.push(i);
        }
        int ans = 0;
        while (!s1.empty() && !s2.empty() && !s3.empty() && !s4.empty() && !s5.empty())
        {
            int flag = 0, pos = s1.front();
            s1.pop();
            while (!s2.empty())
            {
                int now = s2.front();
                s2.pop();
                if (now > pos)
                {
                    flag++;
                    pos = now;
                    break;
                }
            }
            if (flag != 1)
                break;
            while (!s3.empty())
            {
                int now = s3.front();
                s3.pop();
                if (now > pos)
                {
                    flag++;
                    pos = now;
                    break;
                }
            }
            if (flag != 2)
                break;
            while (!s4.empty())
            {
                int now = s4.front();
                s4.pop();
                if (now > pos)
                {
                    flag++;
                    pos = now;
                    break;
                }
            }
            if (flag != 3)
                break;
            while (!s5.empty())
            {
                int now = s5.front();
                s5.pop();
                if (now > pos)
                {
                    flag++;
                    pos = now;
                    break;
                }
            }
            if (flag != 4)
                break;
            else
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}