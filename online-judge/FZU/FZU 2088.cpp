#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a[10000];

int cmp(string a, string b)
{
    return a + b < b + a;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n, cmp);
        string result = "";
        for (int i = 0; i < n; i++)
        {
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}
