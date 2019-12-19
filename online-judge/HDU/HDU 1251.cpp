#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Trie
{
    int child[30];
    int value;

    Trie()
    {
        memset(child, 0, sizeof(child));
        value = 0;
    }
} trie[500007];

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

int search(char str[])
{
    int x = 0;
    for (int i = 0; i < str[i]; i++)
    {
        int k = str[i] - 'a';
        if (trie[x].child[k] == 0)
        {
            return 0;
        }
        x = trie[x].child[k];
    }
    return trie[x].value;
}

int main()
{
    char str[20];
    while (gets(str) && str[0] != '\0')
    {
        insert(str);
    }
    while (gets(str))
    {
        printf("%d\n", search(str));
    }
    return 0;
}