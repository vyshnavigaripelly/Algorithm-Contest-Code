#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    while (cin >> n >> m >> k && (n + m + k))
    {
        long long ans = n * m * k;
        int t;
        int clo[1007] = {0}, pant[1007] = {0}, shoes[1007] = {0};
        int arr[4] = {0, n, m, k};
        cin >> t;
        while (t--)
        {
            string a, b;
            int x, y, flag = 0, flag2 = 0;
            cin >> a >> x >> b >> y;
            if (a == "clothes")
            {
                flag = 1;
                if (clo[x])
                    ans++;
                else
                    clo[x]++;
            }
            else if (a == "pants")
            {
                flag = 2;
                if (pant[x])
                {
                    ans++;
                }
                else
                    pant[x]++;
            }
            else if (a == "shoes")
            {
                flag = 3;
                if (shoes[x])
                {
                    ans++;
                }
                else
                    shoes[x]++;
            }

            if (b == "clothes")
            {
                flag2 = 1;
                if (clo[x])
                    ans++;
                else
                    clo[x]++;
            }
            else if (b == "pants")
            {
                flag2 = 2;
                if (pant[x])
                {
                    ans++;
                }
                else
                    pant[x]++;
            }
            else if (b == "shoes")
            {
                flag2 = 3;
                if (shoes[x])
                {
                    ans++;
                }
                else
                    shoes[x]++;
            }
            for (int i = 1; i <= 3; i++)
            {
                if (flag == i || flag2 == i)
                    continue;
                else
                    ans -= arr[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}