#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n, ans = (1 << 30) - 5;
    string str, tar = "ACTG";
    cin >> n >> str;
    for (int i = 0; i < n - 3; i++)
    {
        int now = 0;
        for (int j = 0; j < 4; j++)
        {
            now += min(abs(str[i + j] - tar[j]), 26 - abs(str[i + j] - tar[j]));
        }
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}