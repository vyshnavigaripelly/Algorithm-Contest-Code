#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        int n, flag = 0;
        cin >> n;
        while (n--)
        {
            int k;
            cin >> k;
            if (k % 3 != 0)
            {
                flag = 1;
            }
        }
        cout << "Case #" << cas << ": " << (flag ? "No" : "Yes") << endl;
    }
    return 0;
}