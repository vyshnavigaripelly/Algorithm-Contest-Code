#include <iostream>
using namespace std;

int arr[1000007], ans[1000007];

int main()
{
    int n;
    while (cin >> n)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            int pos = -1, minn = 0x3f3f3f3f;
            for (int j = 0; j < cnt; j++)
            {
                if (arr[i] <= ans[j] && minn > ans[j] - arr[i])
                {
                    minn = ans[j] - arr[i];
                    pos = j;
                }
            }
            if (pos == -1)
            {
                ans[cnt++] = arr[i];
            }
            else
            {
                ans[pos] = arr[i];
            }
        }
        cout << cnt << endl;
    }
    return 0;
}