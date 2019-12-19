#include <iostream>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

rope<int> rp;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        rp.push_back(i);
    }
    while (m--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        rope<int> cur = rp.substr(l, r);
        rp.erase(l, r);
        rp.insert(rp.mutable_begin(), cur);
    }
    for (int i : rp)
    {
        printf("%d ", i);
    }
    return 0;
}