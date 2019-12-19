#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, vote[1100] = {0};
        cin >> n;
        int in, max = 0, pos = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> in;
            vote[in]++;
            if (vote[in] > max)
            {
                max = vote[in];
                pos = in;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= 1000; i++)
        {
            if (vote[i] == max)
            {
                cnt++;
            }
        }
        if (cnt == 1)
        {
            cout << pos << endl;
        }
        else
        {
            cout << "Nobody" << endl;
        }
    }
    return 0;
}
