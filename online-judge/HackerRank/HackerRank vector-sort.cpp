#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        vec.push_back(k);
    }
    sort(vec.begin(), vec.end());
    for (int i : vec)
    {
        cout << i << ' ';
    }
    return 0;
}