#include <iostream>
#include <string>

using namespace std;

int fun(string str)
{
    int countTime = str.size() - 1;
    string ini = str;
    while (countTime--)
    {
        str.push_back(str[0]);
        str.erase(str.begin());
        if (str < ini)
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int flag[2007] = {0};
        string str;
        cin >> str;
        int st = 0;
        while (st < str.size())
        {
            int tmped = str.size() - 1;
            while (tmped >= st)
            {
                if (fun(str.substr(st, tmped - st + 1)))
                {
                    flag[tmped] = 1;
                    st = tmped + 1;
                    break;
                }
                tmped--;
                if (tmped < st)
                {
                    st = str.size() + 1;
                    break;
                }
            }
        }
        for (int i = 0; i < str.size(); i++)
        {
            cout << str[i];
            if (flag[i])
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}