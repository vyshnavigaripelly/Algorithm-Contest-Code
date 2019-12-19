#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        int star = 0, ans = 0, digit = 0;
        cin >> str;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '*')
                star++;
        }
        digit = star - (str.size() - star - 1);
        if (digit < 0)
            digit = 0;
        ans = digit;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != '*') //数字进栈
                digit++;
            else //读到运算符
            {
                if (digit >= 2) //栈内数字大于2，不需要移动
                    digit--;
                else //数字小于2，移动一个数字进来，计算后再次进栈。
                {
                    digit++;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}