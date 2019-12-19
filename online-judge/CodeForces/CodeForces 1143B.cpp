#include <iostream>
#include <cmath>

using namespace std;

const int N = 200000 + 7;

int arr[N];

long long check(long long n)
{
    long long ans = 1;
    while (n)
    {
        ans *= n % 10;
        n /= 10;
    }
    return ans;
}

int main()
{
    long long n, sum = 0, cnt = -1, ans = 1;
    cin >> n;
    sum = check(n);
    ans = n;
    while (n)
    {
        cnt++;
        if (n % 10 != 9)
        {
            ans -= (n % 10 + 1) * pow(10, cnt);
            cnt = 0;
            n = ans;
            if (ans < 0)
            {
                break;
            }
            if (check(ans) > sum)
            {
                sum = check(ans);
            }
        }
        n /= 10;
    }
    cout << sum << endl;
    return 0;
}