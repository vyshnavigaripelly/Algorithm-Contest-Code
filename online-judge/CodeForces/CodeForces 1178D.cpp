#include <iostream>

using namespace std;

int prime(int n)
{
    if (n == 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    int cnt = n;
    while (!prime(cnt))
    {
        cnt++;
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ' ' << i % n + 1 << endl;
    }
    int now = 1;
    while (cnt != n)
    {
        cout << now << ' ' << n - now << endl;
        now++;
        cnt--;
    }
    return 0;
}