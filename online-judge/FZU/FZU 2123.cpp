#include <iostream>
using namespace std;

int main()
{
    int t, h[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            sum += h[s[i] - '0'];
        }
        cout << sum << endl;
    }
    return 0;
}
