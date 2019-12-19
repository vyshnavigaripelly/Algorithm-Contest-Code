#include <iostream>
#include <algorithm>

using namespace std;

int arr[100007];

int main()
{
    int n;
    cin >> n;
    int maxlen = 0, maxn = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxn = max(maxn, arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int j = i, len = 0;
        while (j < n && arr[i] == arr[j])
        {
            if (arr[j] == maxn)
            {
                len++;
            }
            j++;
        }
        maxlen = max(len, maxlen);
        i = j - 1;
    }
    cout << maxlen << endl;
    return 0;
}