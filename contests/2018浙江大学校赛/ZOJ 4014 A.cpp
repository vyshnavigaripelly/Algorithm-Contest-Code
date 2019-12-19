#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int s = m * n, cnt = 0;
        while (s--)
        {
            int k;
            cin >> k;
            if (k < a || k > b)
            {
                cnt++;
            }
        }
        if (a > b)
        {
            cout << "No Solution" << endl;
        }
        else
        {
            cout << cnt << endl;
        }
    }
    return 0;
}
