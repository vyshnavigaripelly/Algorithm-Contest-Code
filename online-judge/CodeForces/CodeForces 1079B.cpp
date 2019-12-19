#include <iostream>
#include <string>

using namespace std;

int arr[7][27];

int main()
{
    string str;
    cin >> str;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            arr[i][j] = i * j;
        }
    }
    int len = str.size(), r = -1, c = -1;
    int flag = 0;
    for (int i = 1; i <= 5 && !flag; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            if (arr[i][j] >= len)
            {
                r = i;
                c = j;
                flag = 1;
                break;
            }
        }
    }
    int add = r * c - len, e, left, cnt = 0;
    e = add / r, left = add - e * r;
    cout << r << ' ' << c << endl;
    for (int i = 0; i < r; i++)
    {
        int nowl = 0;
        if (add != 0)
        {
            if (left != 0)
            {
                cout << '*';
                left--;
                nowl++;
            }
            for (int i = 0; i < e; i++)
            {
                cout << '*';
                add--;
                nowl++;
            }
        }
        for (int i = nowl; i < c; i++)
        {
            cout << str[cnt];
            cnt++;
        }
        cout << endl;
    }
    return 0;
}
