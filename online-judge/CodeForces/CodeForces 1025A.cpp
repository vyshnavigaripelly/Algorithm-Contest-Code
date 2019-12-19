#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[30];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        arr[s[i] - 'a']++;
    }
    cout << (n == 1 || *max_element(arr, arr + 27) >= 2 ? "Yes" : "No") << endl;
    return 0;
}