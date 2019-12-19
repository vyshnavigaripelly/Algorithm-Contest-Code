#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string in;
        cin >> in;
        char prev = in[0];
        int cnt = 1, len = in.length();
        for (int i = 1; i < len + 1; i++)
        {
            if (in[i] == prev)
            {
                cnt++;
                if (i < len - 1)
                    continue;
            }
            else
            {
                if (cnt > 1)
                {
                    cout << cnt;
                }
                cout << prev;
                prev = in[i];
                cnt = 1;
            }
        }
        cout << endl;
    }
    return 0;
}
