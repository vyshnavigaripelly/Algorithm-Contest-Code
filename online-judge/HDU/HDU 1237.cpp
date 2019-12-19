#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    double n;
    char c;
    while (~scanf("%lf%c", &n, &c) && !(n == 0 && c == '\n'))
    {
        double ans = 0;
        stack<double> s;
        s.push(n);
        char op;
        while (scanf("%c %lf", &op, &n))
        {
            switch (op)
            {
                case '+':
                {
                    s.push(n);
                    break;
                }
                case '-':
                {
                    s.push(-n);
                    break;
                }
                case '*':
                {
                    double tmp = s.top();
                    s.pop();
                    s.push(tmp * n);
                    break;
                }
                case '/':
                {
                    double tmp = s.top();
                    s.pop();
                    s.push(tmp / n);
                    break;
                }
            }
            if ((c = getchar()) == '\n')
            {
                break;
            }
        }
        while (!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
