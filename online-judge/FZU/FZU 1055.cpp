#include <iostream>
using namespace std;

int main()
{
    int t;
    while (cin >> t && t != -1)
    {
        int flag[26] = {1};
        while (t--)
        {
            char va, vb, tmp;
            cin >> va >> tmp >> vb;
            if (flag[vb - 'a'] == 1)
            {
                flag[va - 'a'] = 1;
            }
            else
            {
                flag[va - 'a'] = 0;
            }
        }
        int has = 0;
        for (int i = 0; i < 26; i++)
        {
            if (flag[i] == 1)
            {
                if (has)
                {
                    cout << ' ';
                }
                has = 1;
                cout << char(i + 'a');
            }
        }
        if (!has)
        {
            cout << "none";
        }
        cout << endl;
    }
    return 0;
}