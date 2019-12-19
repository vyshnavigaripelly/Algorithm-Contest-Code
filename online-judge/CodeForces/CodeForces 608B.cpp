#include <iostream>
#include <string>

using namespace std;

long long sum[200007];

int main()
{
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < b.length(); i++)
    {
        sum[i + 1] = sum[i] + b[i] - '0';
    }
    long long ans = 0, len = b.length() - a.length() + 1;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '1')
        {
            ans += len - (sum[i + len] - sum[i]);
        }
        else
        {
            ans += (sum[i + len] - sum[i]);
        }
    }
    cout << ans << endl;
    return 0;
}