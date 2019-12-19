#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n, cas = 1;
    while (cin >> n)
    {
        int ans = 0;
        while (n--)
        {
            string s;
            cin >> s;
            int len = s.length();
            map<char, int> cnt;
            set<int> cnt2;
            for (int i = 0; i < len; i++)
            {
                cnt[s[i]]++;
            }
            for (auto k : cnt)
            {
                cnt2.insert(k.second);
            }
            if (cnt.size() != 1 && cnt.size() == cnt2.size())
            {
                ans++;
            }
        }
        cout << "Case " << cas << ": " << ans << endl;
        cas++;
    }
    return 0;
}
