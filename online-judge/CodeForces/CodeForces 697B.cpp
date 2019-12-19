#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int a;
    string d;
    int b;
    scanf("%d.", &a);
    getline(cin, d, 'e');
    scanf("%d", &b);
    // 1.234e2 123.4
    // 1.234e3 1234
    // 0.1234e3 123.4
    // 0.1234e4 1234
    // 1.2345e6 1234500
    // 0.123e0 0.123
    // 0.00123e2 0.123
    // 0.0001234e2 0.01234 pos=3
    // 0.0001234e5 12.34
    int len = d.length();
    string ans = to_string(a) + d;
    if (b - len > 0)
    {
        ans += string(b - len, '0');
    }
    int dotpos = b + 1;
    ans.insert(ans.begin() + dotpos, '.');
    int l = 0, r = ans.length();
    int m = ans.find_first_not_of('0'), n = ans.find_last_not_of('0');
    if (m == dotpos)
    {
        l = dotpos - 1;
    }
    else
    {
        l = m;
    }
    if (n == dotpos)
    {
        r = n;
    }
    cout << string(ans, l, r - l) << endl;
    return 0;
}
