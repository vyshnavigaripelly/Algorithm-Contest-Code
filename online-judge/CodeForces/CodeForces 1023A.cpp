#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2;
    int n, m, stp = -1;
    cin >> n >> m;
    cin >> str1 >> str2;
    for (int i = 0; i < n; i++)
    {
        if (str1[i] == '*')
        {
            stp = i;
        }
    }
    int len = m - n;
    int flag = 1;
    if (stp == -1 && str1 != str2)
    {
        cout << "NO" << endl;
        return 0;
    }
    if (len < -1)
    {
        flag = 0;
    }
    else
    {
        for (int i = 0, j = 0; i < n && j < m; i++, j++)
        {
            if (str1[i] == '*')
            {
                j += len;
                continue;
            }
            else if (str1[i] != str2[j])
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}