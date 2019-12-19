#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, flag[6] = {0};
    string col[6] = {"purple", "green", "blue", "orange", "red", "yellow"};
    string name[6] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};
    cin >> n;
    cout << 6 - n << endl;
    while (n--)
    {
        string s;
        cin >> s;
        flag[find(col, col + 6, s) - col] = 1;
    }
    for (int i = 0; i < 6; i++)
    {
        if (flag[i] == 0)
        {
            cout << name[i] << endl;
        }
    }
    return 0;
}
