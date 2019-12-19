#include <iostream>

using namespace std;

int main()
{
    int n, p, s, nn, pp, ss, ans = 0;
    cin >> n >> p >> s >> nn >> pp >> ss;
    if (n > nn)
        ans = 1;
    else if (n == nn && p < pp)
        ans = 1;
    else if (n == nn && p == pp && s < ss)
        ans = 1;
    else if (n == nn && s == ss && p == pp)
        ans = 0;
    else
        ans = 2;
    if (ans)
        cout << ans << endl;
    else
        cout << "God" << endl;
    return 0;
}