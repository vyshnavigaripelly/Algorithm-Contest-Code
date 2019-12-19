#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string arr[12];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        string ans = "ZZ";
        int find = 0;
        for (int len = 60; len >= 3; len--)
        {
            for (int i = 0; i <= 60 - len; i++)
            {
                string tmp = string(arr[0], i, len);
                int flag = 1;
                for (int j = 1; j < n; j++)
                {
                    if (arr[j].find(tmp) == string::npos)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    ans = min(ans, tmp);
                    find = 1;
                }
            }
            if (find)
            {
                break;
            }
        }
        if (find)
        {
            cout << ans << endl;
        }
        else
        {
            cout << "no significant commonalities" << endl;
        }
    }
    return 0;
}
