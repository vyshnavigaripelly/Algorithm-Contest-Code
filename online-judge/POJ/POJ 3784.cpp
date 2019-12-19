#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> small;
priority_queue<int> big;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        while (!big.empty())
        {
            big.pop();
        }
        while (!small.empty())
        {
            small.pop();
        }
        int idx, n;
        cin >> idx >> n;
        int x;
        vector<int> ans;
        cin >> x;
        big.push(x);
        ans.push_back(x);
        for (int i = 2; i <= n; i++)
        {
            cin >> x;
            if (big.empty())
            {
                big.push(x);
            }
            else
            {
                if (x > big.top())
                {
                    small.push(x);
                }
                else
                {
                    big.push(x);
                }
            }
            while (big.size() < small.size())
            {
                big.push(small.top());
                small.pop();
            }
            while (small.size() < big.size() - 1)
            {
                small.push(big.top());
                big.pop();
            }
            if (i % 2 == 1)
            {
                ans.push_back(big.top());
            }
        }
        cout << idx << ' ' << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " \n"[i % 10 == 9];
        }
        cout << endl;
    }
    return 0;
}