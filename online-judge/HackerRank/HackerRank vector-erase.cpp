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
    int x, a, b;
    cin >> x >> a >> b;
    x--, a--, b--;
    vec.erase(vec.begin() + x);
    vec.erase(vec.begin() + a, vec.begin() + b);
    cout << vec.size() << endl;
    for (int i : vec)
    {
        cout << i << ' ';
    }
    return 0;
}