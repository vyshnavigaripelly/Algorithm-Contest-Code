#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[2007][30];

struct Trie
{
    int child[30];
    int value;

    Trie()
    {
        memset(child, 0, sizeof(child));
        value = 0;
    }
} trie[5007];

int trieN;

void insert(char str[])
{
    int x = 0;
    for (int i = 0; str[i]; i++)
    {
        int k = str[i] - 'a';
        if (trie[x].child[k] == 0)
        {
            trie[x].child[k] = ++trieN;
        }
        x = trie[x].child[k];
        trie[x].value++;
    }
}

void search(char str[])
{
    int x = 0, len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (trie[x].value == 1)
        {
            break;
        }
        printf("%c", str[i]);
        int k = str[i] - 'a';
        x = trie[x].child[k];
    }
}

int main()
{
    int n = 0;
    while (~scanf("%s", s[n]))
    {
        insert(s[n++]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s ", s[i]);
        search(s[i]);
        puts("");
    }
    return 0;
}