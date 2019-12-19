#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        q.push(k);
    }
    int sum = 0;
    while (k--)
    {
        while (!q.empty() && q.top() == sum)
        {
            q.pop();
        }
        if (q.empty())
        {
            cout << 0 << endl;
        }
        else
        {
            cout << q.top() - sum << endl;
        }
        sum = q.top();
    }
    return 0;
}