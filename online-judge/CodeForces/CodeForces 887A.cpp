#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int len = str.length(), flag1 = 0, flag2 = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == '0')
        {
            flag1++;
        }
        if (flag1 >= 6 && str[i] == '1')
        {
            flag2 = 1;
            break;
        }
    }
    if (flag1 && flag2)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}
