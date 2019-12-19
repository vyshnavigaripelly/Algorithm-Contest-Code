#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> q;
        while (n--)
        {
            int k;
            cin >> k;
            q.push(k);
        }
        int ans = 0;
        while (q.size() > 1)
        {
            int tmp = 0;
            tmp += q.top();
            q.pop();
            tmp += q.top();
            q.pop();
            q.push(tmp);
            ans += tmp;
        }
        cout << ans << endl;
    }
    return 0;
}