#include <iostream>
#include <vector>
using namespace std;

int arr[1007], brr[1007];
vector<int> ans;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = n; i >= 1; i--)
    {
        arr[i] = arr[i] - arr[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        int flag = 1;
        for (int j = 1; j <= n; j++)
        {
            if (arr[j] != arr[(j - 1) % i + 1])
            {
                flag = 0;
            }
        }
        if (flag)
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}