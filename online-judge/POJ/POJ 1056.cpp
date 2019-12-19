#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[1000][50];

struct Trie
{
    int child[5];
    int value;
} trie[500007];

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
    }
    return trie[x].value;
}

int main()
{
    int n = 0, flag = 1, cas = 1;
    while (~scanf("%s", str[n]))
    {
        insert(str[n]);
        if (str[n++][0] == '9')
        {
            for (int i = 0; i < n; i++)
            {
                if (search(str[i]) > 1)
                {
                    flag = 0;
                }
            }
            printf("Set %d is %simmediately decodable\n", cas, (flag ? "" : "not "));
            cas++;
            n = 0;
            flag = 1;
            trieN = 0;
            memset(trie, 0, sizeof(trie));
        }
    }
    return 0;
}