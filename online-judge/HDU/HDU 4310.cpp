#include <iostream>
#include <algorithm>
using namespace std;

struct Hero
{
    int dps;
    int hp;
    double ratio;
};

int cmp(const Hero &a, const Hero &b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n;
    while (cin >> n)
    {
        Hero h[25];
        int sum = 0, dpstotal = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> h[i].dps >> h[i].hp;
            h[i].ratio = 1.0 * h[i].dps / h[i].hp;
            dpstotal += h[i].dps;
        }
        sort(h, h + n, cmp);
        for (int i = 0; i < n; i++)
        {
            sum += dpstotal * h[i].hp;
            dpstotal -= h[i].dps;
        }
        cout << sum << endl;
    }
    return 0;
}
