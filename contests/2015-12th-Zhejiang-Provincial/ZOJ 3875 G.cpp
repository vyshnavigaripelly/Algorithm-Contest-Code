#include <iostream>
#include <algorithm>
using namespace std;

struct mys
{
    string name;
    int price;
};

int cmp(const mys &a, const mys &b)
{
    return a.price < b.price;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s, m, d, money = 0;
        cin >> s >> m >> d;
        mys n1[110], n2[110], n3[110];
        for (int i = 0; i < s; i++)
        {
            cin >> n1[i].name >> n1[i].price;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> n2[i].name >> n2[i].price;
        }
        for (int i = 0; i < d; i++)
        {
            cin >> n3[i].name >> n3[i].price;
        }
        sort(n1, n1 + s, cmp);
        sort(n2, n2 + m, cmp);
        sort(n3, n3 + d, cmp);
        money = n1[s / 2].price + n2[m / 2].price + n3[d / 2].price;
        cout << money << " " << n1[s / 2].name << " " << n2[m / 2].name << " " << n3[d / 2].name << endl;
    }
    return 0;
}
