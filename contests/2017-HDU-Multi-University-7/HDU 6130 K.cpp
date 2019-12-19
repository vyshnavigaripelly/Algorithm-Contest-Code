#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7;
int arr[N];

int main()
{
    int n;
    arr[1] = 1, arr[2] = 2, arr[3] = 2;
    int cnt = 2;
    for (int i = 4, j = 3; i < N; i++, j++)
    {
        if (arr[j] == 1)
        {
            if (cnt == 2)
            {
                arr[i] = 1;
                cnt = 1;
            }
            else
            {
                arr[i] = 2;
                cnt = 2;
            }
        }
        else
        {
            if (cnt == 2)
            {
                arr[i] = 1;
                cnt = 1;
                arr[++i] = 1;
            }
            else
            {
                arr[i] = 2;
                cnt = 2;
                arr[++i] = 2;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << arr[n] << endl;
    }
    return 0;
}