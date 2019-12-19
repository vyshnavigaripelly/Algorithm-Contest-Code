#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 7;

int arr[N];
vector<int> ans = {1};

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int nowsum = arr[1];
    for (int i = 2; i <= n; i++)
    {
        if (arr[1] >= 2 * arr[i])
        {
            ans.push_back(i);
            nowsum += arr[i];
        }
    }
    if (2 * nowsum > sum)
    {
        cout << ans.size() << endl;
        for (auto i : ans)
        {
            cout << i << ' ';
        }
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}