#include <iostream>
using namespace std;

int s[5000];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i, j, find = 0;
        cin >> n >> k;
        for (i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (i = 0; i < n; i++)
        {
            int sum = 0;
            for (j = i; j < n; j++)
            {
                sum += s[j];
                if (sum == k)
                {
                    find = 1;
                    break;
                }
            }
            if (find)
            {
                break;
            }
        }
        cout << i + 1 << " " << j + 1 << endl;
    }
    return 0;
}
