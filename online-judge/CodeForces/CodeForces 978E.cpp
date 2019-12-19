#include <iostream>
using namespace std;

int main()
{
    int n, w, maxin = 0, maxout = 0, change = 0, num;
    cin >> n >> w;
    while (n--)
    {
        cin >> num;
        change += num;
        if (change > maxin)
        {
            maxin = change;
        }
        else if (change < maxout)
        {
            maxout = change;
        }
    }
    if (w - maxin + maxout + 1 < 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << w - maxin + maxout + 1 << endl;
    }
    return 0;
}
