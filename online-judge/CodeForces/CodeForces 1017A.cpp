#include <iostream>
#include <algorithm>
using namespace std;

struct Stu
{
    int sum, id;
} arr[1007];

int cmp(const Stu &a, const Stu &b)
{
    if (a.sum == b.sum)
    {
        return a.id < b.id;
    }
    return a.sum > b.sum;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k;
        for (int j = 0; j < 4; j++)
        {
            cin >> k;
            arr[i].sum += k;
        }
        arr[i].id = i;
    }
    sort(arr + 1, arr + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        if (arr[i].id == 1)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}