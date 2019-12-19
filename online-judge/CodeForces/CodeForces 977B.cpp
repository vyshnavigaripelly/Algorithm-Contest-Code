#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    map<string, int> mm;
    for (int i = 0; i < n - 1; i++)
    {
        mm[string(s, i, 2)]++;
    }
    string maxs;
    int max = 0;
    for (auto it = mm.begin(); it != mm.end(); it++)
    {
        if (it->second > max)
        {
            max = it->second;
            maxs = it->first;
        }
    }
    cout << maxs << endl;
    return 0;
}
