#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const char hexchar[17] = {"0123456789abcdef"};

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        string str, arr[8];
        cin >> str;
        for (int i = 0; i < 8; i++)
        {
            int flag = 0;
            for (int j = 0; j < 4; j++)
            {
                long long tmp = 0;
                for (int k = 0; k < 4; k++)
                {
                    tmp += (str[i * 16 + j * 4 + k] - '0') * (1 << (3 - k));
                }
                if (tmp != 0 || flag == 1)
                {
                    arr[i] += hexchar[tmp];
                    flag = 1;
                }
            }
            if (arr[i].length() == 0)
            {
                arr[i] = "0";
            }
        }
        vector<string> ans;
        string tmp;
        for (int i = 0; i < 8; i++)
        {
            tmp += arr[i];
            if (i != 7)
                tmp += ":";
        }
        ans.push_back(tmp);
        for (int i = 0; i < 8; i++)
        {
            if (arr[i] != "0")
            {
                continue;
            }
            int j = i;
            while (j <= 8)
            {
                if (j == 8 || arr[j] != "0")
                {
                    if (j - i == 1)
                        break;
                    string tmp = "";
                    for (int k = 0; k < i; k++)
                    {
                        tmp += arr[k];
                        if (k != i - 1)
                            tmp += ":";
                    }
                    tmp += "::";
                    for (int k = j; k < 8; k++)
                    {
                        if (k != j)
                            tmp += ":";
                        tmp += arr[k];
                    }
                    ans.push_back(tmp);
                    break;
                }
                j++;
            }
            i = j - 1;
        }
        sort(ans.begin(), ans.end(), [](const string &a, const string &b) {
            return a.length() < b.length() || (a.length() == b.length() && a < b);
        });
        printf("Case #%d: ", cas);
        cout << ans[0] << endl;
    }
    return 0;
}