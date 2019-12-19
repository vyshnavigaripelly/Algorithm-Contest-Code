#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int> pq;
int arr[2007], brr[2007];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        for (int i = 1; i < m; i++)
        {
            while (!pq.empty())
            {
                pq.pop();
            }
            for (int j = 0; j < n; j++)
            {
                cin >> brr[j];
            }
            sort(brr, brr + n);
            for (int j = 0; j < n; j++)
            {
                pq.push(arr[0] + brr[j]);
            }
            for (int j = 1; j < n; j++)
            {
                for (int k = 0; k < n; k++)

                {
                    int sum = arr[j] + brr[k];
                    if (sum < pq.top())
                    {
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
            for (int i = n - 1; i >= 0; i--)
            {
                arr[i] = pq.top();
                pq.pop();
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}