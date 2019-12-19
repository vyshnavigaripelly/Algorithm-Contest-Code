#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100007];
vector<int> ans;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            cnt++;
        }
        else
        {
            ans.push_back(cnt);
            cnt = 1;
        }
    }
    ans.push_back(cnt);
    cout << *max_element(ans.begin(), ans.end()) << endl;
    return 0;
}