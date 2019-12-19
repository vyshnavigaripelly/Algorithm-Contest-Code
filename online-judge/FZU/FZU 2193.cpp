#include <iostream>
using namespace std;

long long Gcd(long long a, long long b)
{
    long long c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int cnt = 0, len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (s[i] != '.')
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        long long a = 0, b = 0, aa = 1, bb = 1;
        for (int i = 0; i < cnt; i++)
        {
            a = s[i] - '0' + a * 10;
            aa *= 10;
        }
        for (int i = cnt + 1; i < len; i++)
        {
            b = s[i] - '0' + b * 10;
            bb *= 10;
        }
        long long left = a * bb + b, right = bb, gcd = Gcd(left, right);
        cout << left / gcd << '/' << right / gcd << endl;
    }
    return 0;
}
