#include <iostream>
using namespace std;

int main()
{
    int n, k, ans[10000];
    while (cin >> n && n != 0)
    {
        int i, j;
        for (i = 2, k = 0; i < n; i++)
        {
            for (j = 2; j < i; j++)
            {
                if (i % j == 0)
                    break;
            }
            if (i == j)
            {
                ans[k] = i;
                k++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (ans[i] + ans[j] == n)
                    cnt++;
            }
        }
        if (cnt % 2 == 0)
        {
            cout << cnt / 2 << endl;
        }
        else
        {
            cout << cnt / 2 + 1 << endl;
        }
    }
    return 0;
}
