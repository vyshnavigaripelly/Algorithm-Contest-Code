#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt[10] = {0};
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int k = i;
            while (k != 0)
            {
                cnt[k % 10]++;
                k /= 10;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            cout << cnt[i];
            if (i < 9)
            {
                cout << ".";
            }
        }
        cout << endl;
    }
    return 0;
}
