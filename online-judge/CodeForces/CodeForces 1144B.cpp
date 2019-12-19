#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

vector<int> even, odd;

int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k % 2 == 1)
        {
            odd.push_back(k);
        }
        else
        {
            even.push_back(k);
        }
        sum += k;
    }
    odd.push_back(0);
    even.push_back(0);
    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end(), greater<int>());
    int m = min(odd.size(), even.size());
    sum -= accumulate(odd.begin(), odd.begin() + m, 0LL) +
           accumulate(even.begin(), even.begin() + m, 0LL);
    cout << sum << endl;
    return 0;
}