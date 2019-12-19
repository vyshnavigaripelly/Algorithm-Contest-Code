#include <iostream>

using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n >> x;
    int cnt = 0;
    while (n--)
    {
        char c;
        long long d;
        cin >> c >> d;
        if (c == '+')
        {
            x += d;
        }
        else
        {
            if (x >= d)
            {
                x -= d;
            }
            else
            {
                cnt++;
            }
        }
    }
    cout << x << ' ' << cnt << endl;
    return 0;
}