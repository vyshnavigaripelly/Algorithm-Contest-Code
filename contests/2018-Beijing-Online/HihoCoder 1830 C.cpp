#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int lexiRank[13] = {10, 2, 3, 4, 5, 6, 7, 8, 9, 1, 11, 13, 12};
const char cardLetter[15][5] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

int table[15], now[15];
char tmp[5];

struct Node
{
    int cards[15];
} p[4];

int check(char c)
{
    if (c == 'A')
        return 1;
    if (c == 'J')
        return 11;
    if (c == 'Q')
        return 12;
    if (c == 'K')
        return 13;
    if (c == '1')
        return 10;
    return c - '0';
}

void statementTrue(int challenger)
{
    for (int i = 1; i <= 13; i++)
    {
        p[challenger].cards[i] += now[i] + table[i];
        now[i] = table[i] = 0;
    }
}

void statementFalse(int holder)
{
    for (int i = 1; i <= 13; i++)
    {
        p[holder].cards[i] += now[i] + table[i];
        now[i] = table[i] = 0;
    }
}

int main()
{
    while (~scanf("%s", tmp))
    {
        memset(table, 0, sizeof(table));
        memset(now, 0, sizeof(now));
        memset(p, 0, sizeof(p));
        p[0].cards[check(tmp[0])]++;
        for (int i = 1; i < 13; i++)
        {
            scanf("%s", tmp);
            p[0].cards[check(tmp[0])]++;
        }
        for (int i = 1; i < 4; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                scanf("%s", tmp);
                p[i].cards[check(tmp[0])]++;
            }
        }
        int winner = -1;
        for (int round = 0;; round++)
        {
            int holder = round % 4;
            int statementRank = round % 13 + 1;
            int statement = 0;
            int stateCards = 1;
            switch (holder)
            {
                case 0:
                {
                    if (p[holder].cards[statementRank] > 0)
                    {
                        statement = 1;
                        p[holder].cards[statementRank]--;
                        now[statementRank]++;
                    }
                    else
                    {
                        for (int i = 0; i < 13; i++)
                        {
                            if (p[holder].cards[lexiRank[i]] > 0)
                            {
                                p[holder].cards[lexiRank[i]]--;
                                now[lexiRank[i]]++;
                                break;
                            }
                        }
                    }
                    break;
                }
                case 1:
                {
                    if (p[holder].cards[statementRank] > 0)
                    {
                        statement = 1;
                        stateCards = p[holder].cards[statementRank];
                        now[statementRank] = p[holder].cards[statementRank];
                        p[holder].cards[statementRank] = 0;
                    }
                    else
                    {
                        for (int i = 0; i < 13; i++)
                        {
                            if (p[holder].cards[lexiRank[i]] > 0)
                            {
                                p[holder].cards[lexiRank[i]]--;
                                now[lexiRank[i]]++;
                                break;
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    if (p[holder].cards[statementRank] > 0)
                    {
                        statement = 1;
                        stateCards = p[holder].cards[statementRank];
                        now[statementRank] = p[holder].cards[statementRank];
                        p[holder].cards[statementRank] = 0;
                    }
                    else
                    {
                        int minn = 10;
                        for (int i = 1; i <= 13; i++)
                        {
                            if (p[holder].cards[i] > 0)
                            {
                                minn = min(minn, p[holder].cards[i]);
                            }
                        }
                        stateCards = minn;
                        for (int i = 0; i < 13; i++)
                        {
                            if (p[holder].cards[lexiRank[i]] == minn)
                            {
                                now[lexiRank[i]] = p[holder].cards[lexiRank[i]];
                                p[holder].cards[lexiRank[i]] = 0;
                                break;
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    if (p[holder].cards[statementRank] >= 3)
                    {
                        statement = 1;
                        stateCards = p[holder].cards[statementRank];
                        now[statementRank] = p[holder].cards[statementRank];
                        p[holder].cards[statementRank] = 0;
                    }
                    else
                    {
                        statement = 1;
                        stateCards = p[holder].cards[statementRank];
                        if (p[holder].cards[statementRank] > 0)
                        {
                            now[statementRank] = p[holder].cards[statementRank];
                            p[holder].cards[statementRank] = 0;
                        }
                        for (int i = 0; i < 13; i++)
                        {
                            if (p[holder].cards[lexiRank[i]] > 0)
                            {
                                statement = 0;
                                p[holder].cards[lexiRank[i]]--;
                                now[lexiRank[i]]++;
                                stateCards++;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            for (int i = 1; i < 4; i++)
            {
                int challenger = (holder + i) % 4;
                if (challenger == 0)
                {
                    if (((holder + 1) % 4 == challenger && p[challenger].cards[(statementRank - 1 + 1) % 13 + 1] == 0) ||
                        stateCards + p[challenger].cards[statementRank] > 4)
                    {
                        statement == 1 ? statementTrue(challenger) : statementFalse(holder);
                        break;
                    }
                }
                else if (challenger == 1)
                {
                    if ((holder + 1) % 4 == challenger && p[challenger].cards[(statementRank - 1 + 1) % 13 + 1] == 0)
                    {
                        statement == 1 ? statementTrue(challenger) : statementFalse(holder);
                        break;
                    }
                }
                else if (challenger == 2)
                {
                    if (p[challenger].cards[statementRank] == 4)
                    {
                        statement == 1 ? statementTrue(challenger) : statementFalse(holder);
                        break;
                    }
                }
                else if (challenger == 3)
                {
                    if (accumulate(p[holder].cards + 1, p[holder].cards + 1 + 13, 0) == 0)
                    {
                        statement == 1 ? statementTrue(challenger) : statementFalse(holder);
                        break;
                    }
                }
            }
            for (int i = 0; i < 4; i++)
            {
                if (accumulate(p[i].cards + 1, p[i].cards + 1 + 13, 0) == 0)
                {
                    winner = i;
                    break;
                }
            }
            if (winner != -1)
            {
                break;
            }
            else
            {
                for (int i = 1; i <= 13; i++)
                {
                    table[i] += now[i];
                    now[i] = 0;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (winner == i)
            {
                puts("WINNER");
                continue;
            }
            for (int j = 1; j <= 13; j++)
            {
                for (int k = 0; k < p[i].cards[j]; k++)
                {
                    printf("%s ", cardLetter[j]);
                }
            }
            puts("");
        }
    }
    return 0;
}