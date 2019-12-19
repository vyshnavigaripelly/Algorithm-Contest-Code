#include <iostream>
using namespace std;

int arr[105];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = arr[i - 1] + s[i - 1] - '0';
    }
    int flag = 0;
    for (int i = 2; i <= arr[n]; i++)
    {
        if (arr[n] % i != 0)
        {
            continue;
        }
        int tmp = 0;
        int next = arr[n] / i;
        for (int j = 1; j <= n; j++)
        {
            if (arr[j] == next)
            {
                next += arr[n] / i;
            }
        }
        if (next == arr[n] + arr[n] / i)
        {
            flag = 1;
            tmp = 1;
        }
    }
    cout << (flag || arr[n] == 0 ? "YES" : "NO") << endl;
    return 0;
}