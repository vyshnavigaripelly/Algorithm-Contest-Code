#include <iostream>
using namespace std;

int main()
{
    int n, h[55], t = 0;
    while (cin >> n && n)
    {
        if (t++)
        {
            cout << endl;
        }
        int sum = 0, avg;
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
            sum += h[i];
        }
        avg = sum / n;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (h[i] > avg)
            {
                cnt += h[i] - avg;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
