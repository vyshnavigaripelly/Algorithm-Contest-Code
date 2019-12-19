#include <iostream>
#include <string>
using namespace std;

int flag[200007];

int main()
{
    int n, m, ans = 0, st = 0;
    string str;
    cin >> n >> m;
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            for (int j = st; j < n; j++)
            {
                if (str[j] == ')' && !flag[j])
                {
                    flag[i] = flag[j] = 1;
                    ans += 2;
                    st = j + 1;
                    break;
                }
            }
        }
        if (ans == m)
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (flag[i])
        {
            cout << str[i];
        }
    }
    return 0;
}