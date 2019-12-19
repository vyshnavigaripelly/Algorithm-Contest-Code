#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[10007][15];

struct Trie
{
    int child[15];
    int value;
} trie[300007];

int trieN;

void insert(char str[])
{
    int x = 0;
    for (int i = 0; str[i]; i++)
    {
        int k = str[i] - '0';
        if (trie[x].child[k] == 0)
        {
            trie[x].child[k] = ++trieN;
        }
        x = trie[x].child[k];
        trie[x].value++;
    }
}

int search(char str[])
{
    int x = 0;
    for (int i = 0; str[i]; i++)
    {
        int k = str[i] - '0';
        x = trie[x].child[k];
        if (trie[x].value == 1)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        trieN = 0;
        int flag = 1;
        memset(trie, 0, sizeof(trie));
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", str[i]);
            insert(str[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (!search(str[i]))
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}