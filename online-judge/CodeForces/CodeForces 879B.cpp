#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[1000];

int main()
{
    long long n, k;
    queue<int> q;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        q.push(arr[i]);
    }
    if (k >= n)
    {
        cout << *max_element(arr, arr + n) << endl;
    }
    else
    {
        int ans = q.front(), sum = 0;
        q.pop();
        while (sum < k)
        {
            if (ans > q.front())
            {
                q.push(q.front());
                q.pop();
                sum++;
            }
            else
            {
                sum = 1;
                q.push(ans);
                ans = q.front();
                q.pop();
            }
        }
        cout << ans << endl;
    }
    return 0;
}