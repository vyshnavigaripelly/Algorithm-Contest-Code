#include <iostream>
using namespace std;

int money[110000];

int main()
{
    int n, m, left = 0, right = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> money[i];
        if (left < money[i])
        {
            left = money[i];
        }
        right += money[i];
    }
    while (left < right)
    {
        int mid = (left + right) / 2, parts = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + money[i] > mid)
            {
                sum = money[i];
                parts++;
            }
            else
            {
                sum += money[i];
            }
        }
        parts++;
        if (parts > m)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    cout << right << endl;
    return 0;
}
