#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        string s;
        cin >> x >> y >> s;
        int len = s.length();
        vector<int> pos;
        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                pos.push_back(i);
            }
        }
        int sum = 0, cur = 0;
        for (int i = 0; i < pos.size(); i++)
        {
            if (s[i] == '0')
            {
                sum += min((pos[cur] - i) * x, y);
                cur++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
