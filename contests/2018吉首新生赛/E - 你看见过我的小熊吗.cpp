#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int b, k, cnt = 0, max = 0;
        cin >> b;
        while (b--)
        {
            cin >> k;
            if (k == 8)
            {
                cnt++;
                if (cnt > max)
                {
                    max = cnt;
                }
            }
            else
            {
                cnt = 0;
            }
        }
        cout << max << endl;
    }
    return 0;
}
