#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[400007];
vector<int> ans;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    n *= 2;
    ans.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n && arr[i] == arr[j])
        {
            j++;
        }
        if (arr[i] == 1)
        {
            ans.push_back(j - i);
        }
        i = j - 1;
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
    return 0;
}