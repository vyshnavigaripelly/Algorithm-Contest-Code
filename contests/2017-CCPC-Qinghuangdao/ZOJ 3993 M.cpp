#include <iostream>
#include <cmath>
#include <algorithm>

#define pi acos(-1.0)

using namespace std;
struct node
{
    int x, y, num;
    double dis;
};

node arr[1007];

double AREA(node a, double r1, node b, double r2)
{
    double d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    if (d >= r1 + r2)
        return 0;
    if (r1 > r2)
    {
        double tmp = r1;
        r1 = r2;
        r2 = tmp;
    }
    if (r2 - r1 >= d)
        return pi * r1 * r1;
    double ang1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
    double ang2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
    return ang1 * r1 * r1 + ang2 * r2 * r2 - r1 * d * sin(ang1);
}

bool cmp(node a, node b)
{
    if (a.dis != b.dis)
        return a.dis > b.dis;
    return a.num < b.num;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r1, r2;
        node p;
        p.x = 0, p.y = 0;
        cin >> n >> r1 >> r2;
        for (int i = 1; i <= n; i++)
        {
            node pp;
            cin >> arr[i].x >> arr[i].y;
            pp.x = arr[i].x, pp.y = arr[i].y;
            arr[i].num = i;
            arr[i].dis = AREA(p, r1 - r2, pp, r2);
        }
        sort(arr + 1, arr + 1 + n, cmp);
        int tmp = 1, sum = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i].dis == arr[i + 1].dis)
            {
                sum++, tmp++;
            }
            else
                break;
        }
        cout << sum << endl;
        cout << arr[1].num;
        for (int i = 2; i <= tmp; i++)
            cout << " " << arr[i].num;
        cout << endl;
    }
}