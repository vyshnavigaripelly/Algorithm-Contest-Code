#include <iostream>
#include <cstdio>

using namespace std;

int shelf[900007], pos[200007];

int main()
{
    int q, head = 500000, tail = 500001;
    scanf("%d", &q);
    while (q--)
    {
        char c;
        int k;
        scanf(" %c %d", &c, &k);
        if (c == 'L')
        {
            pos[k] = head;
            shelf[head] = k;
            head--;
        }
        else if (c == 'R')
        {
            pos[k] = tail;
            shelf[tail] = k;
            tail++;
        }
        else if (c == '?')
        {
            printf("%d\n", min(pos[k] - head - 1, tail - pos[k] - 1));
        }
    }
    return 0;
}