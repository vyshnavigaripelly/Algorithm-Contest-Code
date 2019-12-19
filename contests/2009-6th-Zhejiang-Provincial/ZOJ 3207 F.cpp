#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    map<string, int> m;
    while (t--)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    int k;
    cin >> k;
    while (k--)
    {
        int n, cnt = 0;
        cin >> n;
        while (n--)
        {
            string ss;
            cin >> ss;
            if (m[ss] > 0)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
