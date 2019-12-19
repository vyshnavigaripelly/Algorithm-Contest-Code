#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        cin >> n;
        while (n--)
        {
            int mmr;
            cin >> mmr;
            if (mmr > 6000)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
