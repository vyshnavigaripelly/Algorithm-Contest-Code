#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <list>

using namespace std;

list<pair<long long, int>> li;
unordered_map<long long, list<pair<long long, int>>::iterator> mp;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        li.clear();
        mp.clear();
        int q, m;
        scanf("%d %d", &q, &m);
        while (q--)
        {
            int op, v;
            char str[15];
            scanf("%d %s %d", &op, str, &v);
            long long k = 1;
            for (int i = 0; str[i]; i++)
            {
                k = k * 10 + str[i] - '0';
            }
            if (op == 0)
            {
                auto mpit = mp.find(k);
                if (mpit != mp.end())
                {
                    auto liit = mpit->second;
                    printf("%d\n", (*liit).second);
                    li.insert(li.end(), liit, next(liit));
                    li.erase(liit);
                }
                else
                {
                    li.push_back({k, v});
                    printf("%d\n", v);
                }
                mp[k] = --li.end();
                while (li.size() > m)
                {
                    mp.erase((*li.begin()).first);
                    li.pop_front();
                }
            }
            else
            {
                auto mpit = mp.find(k);
                if (mpit != mp.end())
                {
                    auto liit = mpit->second;
                    if ((v == 1 && liit == --li.end()) || (v == -1 && liit == li.begin()))
                    {
                        puts("Invalid");
                    }
                    else
                    {
                        advance(liit, v);
                        printf("%d\n", (*liit).second);
                    }
                }
                else
                {
                    puts("Invalid");
                }
            }
        }
    }
    return 0;
}