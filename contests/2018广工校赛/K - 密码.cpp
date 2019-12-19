#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string in;
        cin >> n >> in;
        int len = in.length();
        int k = 2 * (n - 1);
        if (n == 1)
        {
            cout << in << endl;
        }
        else
        {
            for (int row = 0; row < n; row++)
            {
                for (int i = 0; i <= len / k; i++)
                {
                    int a = i * k + row, b = (i + 1) * k - row;
                    if (a < len)
                        cout << in[a];
                    if (row != 0 && row != n - 1 && b < len)
                        cout << in[b];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
