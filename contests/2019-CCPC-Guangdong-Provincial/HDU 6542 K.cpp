#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<string, int> mp;

int main()
{
    char s[10];
    for (int i = 0; i < 14; i++)
    {
        scanf("%s", s);
        mp[s]++;
    }
    if (mp.size() == 13)
    {
        puts("shisanyao!");
        return 0;
    }
    else if (mp.size() == 9)
    {
        int flag = 1;
        auto it = mp.begin(), ed = --mp.end(), it1 = it;
        string tar = it->first;
        while (it1 != mp.end())
        {
            string now = it1->first;
            if (now[1] != tar[1])
            {
                flag = 0;
                break;
            }
            it1++;
        }
        if (!flag)
        {
            puts("I dont know!");
            return 0;
        }
        else if (it->second >= 3 && ed->second >= 3)
        {
            puts("jiulianbaodeng!");
            return 0;
        }
        puts("I dont know!");
        return 0;
    }
    puts("I dont know!");
    return 0;
}