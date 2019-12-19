#include <iostream>
#include <map>

using namespace std;

map<char, int> timezone = {{'B', 8}, {'W', -5}, {'L', 0}, {'M', 3}};
char dayStr[3][20] = {"Yesterday", "Today", "Tomorrow"};

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int h, m;
        char s[3];
        char cityNow[20], cityAfter[20];
        scanf("%d:%d %s %s %s", &h, &m, s, cityNow, cityAfter);
        if (h == 12)
        {
            h = 0;
        }
        if (s[0] == 'P')
        {
            h += 12;
        }
        int delta = timezone[cityAfter[0]] - timezone[cityNow[0]];
        h += delta;
        int day;
        if (h < 0)
        {
            day = 0;
        }
        else if (h >= 0 && h < 24)
        {
            day = 1;
        }
        else if (h >= 24)
        {
            day = 2;
        }
        h = (h + 24) % 24;
        printf("Case %d: %s %d:%02d %s\n", cas, dayStr[day], h % 12 == 0 ? 12 : h % 12, m, h >= 12 ? "PM" : "AM");
    }
    return 0;
}