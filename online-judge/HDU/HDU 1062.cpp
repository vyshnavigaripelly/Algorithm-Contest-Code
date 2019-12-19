#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        int begin = 0;
        string str;
        getline(cin, str);
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
            {
                for (int j = i - 1; j >= begin; j--)
                {
                    cout << str[j];
                }
                cout << ' ';
                begin = i + 1;
            }
            if (i == str.length() - 1)
            {
                for (int j = i; j >= begin; j--)
                {
                    cout << str[j];
                }
            }
        }
        cout << endl;
    }
    return 0;
}
