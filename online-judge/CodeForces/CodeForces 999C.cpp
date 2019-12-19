#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

typedef pair<char, int> pa;

int cmp(const pa &a, const pa &b)
{
    return a.second < b.second;
}

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    pa arr[412345];
    for (int i = 0; i < n; i++)
    {
        arr[i] = make_pair(s[i], i);
    }
    sort(arr, arr + n);
    sort(arr + k, arr + n, cmp);
    for (int i = k; i < n; i++)
    {
        cout << arr[i].first;
    }
    cout << endl;
    return 0;
}