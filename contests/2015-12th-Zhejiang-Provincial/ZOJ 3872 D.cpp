#include <iostream>
#include <cstring>
using namespace std;

long long sum = 0, sum2 = 0;
int a[100001];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        int n, q;
        sum = 0, sum2 = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> q;
            sum2 = (i - a[q]) * q + sum2;
            sum += sum2;
            a[q] = i;
        }
        cout << sum << endl;
    }
    return 0;
}
