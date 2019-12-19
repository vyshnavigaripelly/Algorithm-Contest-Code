#include <iostream>
#include <cmath>
using namespace std;

int arr[40007];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, manx = -1, ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            manx = max(manx, arr[i]);
            ans += arr[i];
        }
        int anss = ans / m;
        if (ans % m != 0)
            anss++;
        manx = max(manx, anss);
        cout << manx << endl;
    }

    return 0;
}