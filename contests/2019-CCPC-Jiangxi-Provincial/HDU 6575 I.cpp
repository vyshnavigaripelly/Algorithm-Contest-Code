#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ans += (s[s.length() - 1] <= '4' ? -(s[s.length() - 1] - '0') : 10 - (s[s.length() - 1] - '0'));
    }
    printf("%.3f\n", ans / 1000.0);
    return 0;
}