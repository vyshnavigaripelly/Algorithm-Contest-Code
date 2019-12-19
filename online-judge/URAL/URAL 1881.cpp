#include <iostream>
#include <string>

using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    int res = w, cnt = 1;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int len = str.length();
        if (res < len)
        {
            cnt++;
            res = w;
        }
        res -= len + 1;
        if (res <= 0)
        {
            cnt++;
            res = w;
        }
    }
    if (res == w)
    {
        cnt--;
    }
    cout << (cnt + (h - 1)) / h << endl;
    return 0;
}