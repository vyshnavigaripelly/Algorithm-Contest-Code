#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;

struct node
{
    int val, pos;
} arr[N];

int cmp(const node &a, const node &b)
{
    return a.val != b.val ? a.val > b.val : a.pos > b.pos;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i].val;
            arr[i].pos = i;
        }
        sort(arr + 1, arr + 1 + n, cmp);
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (arr[j].pos % i != 0)
                {
                    if (i == 2)
                        cout << arr[j].val;
                    else
                        cout << " " << arr[j].val;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}