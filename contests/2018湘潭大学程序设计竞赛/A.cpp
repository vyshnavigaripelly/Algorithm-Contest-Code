#include <iostream>
#include <cstdio>

using namespace std;

long long DhmsToSec(int dd, int hh, int mm, int ss)
{
    return ((dd * 24 + hh) * 60 + mm) * 60 + ss;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int sd, sh, sm, ss, ed, eh, em, es;
        scanf("%dday%d:%d:%d", &sd, &sh, &sm, &ss);
        scanf("%dday%d:%d:%d", &ed, &eh, &em, &es);
        printf("%lld\n", DhmsToSec(ed, eh, em, es) - DhmsToSec(sd, sh, sm, ss));
    }
    return 0;
}