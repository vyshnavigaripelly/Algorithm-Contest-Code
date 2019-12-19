#include <iostream>

using namespace std;

int main()
{
    string s[] = {"Typically Otaku",
                  "Eye-opener",
                  "Young Traveller",
                  "Excellent Traveller",
                  "Contemporary Xu Xiake"};
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int cnt = 0;
        for (auto i : {a, b, c, d})
        {
            if (i)
            {
                cnt++;
            }
        }
        cout << s[cnt] << endl;
    }
    return 0;
}