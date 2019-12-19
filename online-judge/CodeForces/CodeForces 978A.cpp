#include <iostream>
#include <stack>
using namespace std;

int arr[100], vis[1200], ans[100];

int main()
{
    int n, cnt = 0;
    stack<int> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (vis[arr[i]] == 0)
        {
            s.push(arr[i]);
            vis[arr[i]] = 1;
        }
    }
    cout << s.size() << endl;
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}
