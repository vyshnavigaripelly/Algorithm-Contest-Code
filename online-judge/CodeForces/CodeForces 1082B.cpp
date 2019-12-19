#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, pos = 0, sum = 0, ans = 0, minx = 0;
    string str;
    cin >> n >> str;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'G')
        {
            sum++;
            pos++;
        }
        else
        {
            ans = sum, sum = 0;
        }
        minx = max(minx, ans + sum + 1);
    }
    cout << min(minx, pos) << endl;
    return 0;
}