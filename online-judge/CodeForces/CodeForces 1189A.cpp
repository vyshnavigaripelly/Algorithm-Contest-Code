#include <iostream>
#include <string>

using namespace std;

int cnt[2];

int main()
{
    int n;
    string str;
    cin >> n >> str;
    for (int i = 0; i < n; i++)
    {
        cnt[str[i] - '0']++;
    }
    if (cnt[0] != cnt[1])
    {
        cout << 1 << endl
             << str << endl;
    }
    else
    {
        cout << 2 << endl;
        for (int i = 0; i < n; i++)
        {
            int cntleft[2] = {0}, cntright[2] = {0};
            for (int j = 0; j < i + 1; j++)
            {
                cntleft[str[j] - '0']++;
            }
            for (int j = i + 1; j < n; j++)
            {
                cntright[str[j] - '0']++;
            }
            if (cntleft[0] != cntleft[1] && cntright[0] != cntright[1])
            {
                cout << str.substr(0, i + 1) << ' ' << str.substr(i + 1) << endl;
                break;
            }
        }
    }
    return 0;
}