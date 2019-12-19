#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[5], cnt = 0;
        for (int i = 0; i < 5; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < 16; i++)
        {
            bitset<4> b(i);
            int sum = a[0];
            for (int j = 3; j >= 0; j--)
            {
                sum += (b[j] ? 1 : -1) * a[4 - j];
            }
            if (sum == 24)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
