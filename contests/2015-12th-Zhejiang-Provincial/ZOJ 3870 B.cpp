#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[100001], b[100001];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        long long sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int ans = 0;
            int temp = a[i];
            while (temp)
            {
                ans++;
                if (temp % 2 == 0)
                {
                    sum += b[ans];
                }
                temp /= 2;
            }
            b[ans]++;
        }
        cout << sum << endl;
    }
    return 0;
}
