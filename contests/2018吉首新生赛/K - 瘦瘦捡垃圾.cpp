#include <iostream>
#include <algorithm>
using namespace std;

int b[10000];

int main()
{
    int x, v;
    while (cin >> x >> v)
    {
        for (int i = 0; i < x; i++)
        {
            cin >> b[i];
        }
        sort(b, b + x, greater<int>());
        int cnt = 0, s = 0, flag = 0;
        for (int i = 0; i < x; i++)
        {
            s += b[i];
            cnt++;
            if (s >= v)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {

            cout << cnt << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
