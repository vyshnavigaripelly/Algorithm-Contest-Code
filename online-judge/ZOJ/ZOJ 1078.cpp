#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

bool judge(int n, int r)
{
    int k = n;
    string str = "0123456789ABCDEF", result = "";
    do
    {
        result += str[k % r];
        k /= r;
    } while (k != 0);
    return string(result.rbegin(), result.rend()) == result;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        int flag = 0;
        cout << "Number " << n << " is ";
        for (int i = 2; i <= 16; i++)
        {
            if (judge(n, i))
            {
                if (!flag)
                {
                    cout << "palindrom in basis";
                }
                flag = 1;
                if (flag)
                {
                    cout << " " << i;
                }
            }
        }
        if (!flag)
        {
            cout << "not a palindrom";
        }
        cout << endl;
    }
    return 0;
}