#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char m[500][500];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int h, w;
        scanf("%d %d", &h, &w);
        memset(m, '.', sizeof(m));
        if (h % 2 == 1 && w % 2 == 1)
        {
            memset(m, '(', sizeof(m));
        }
        else if (h % 2 == 1)
        {
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j += 2)
                {
                    m[i][j] = '(';
                    m[i][j + 1] = ')';
                }
            }
        }
        else if (w % 2 == 1)
        {
            for (int i = 0; i < h; i += 2)
            {
                for (int j = 0; j < w; j++)
                {
                    m[i][j] = '(';
                    m[i + 1][j] = ')';
                }
            }
        }
        else
        {
            if (min(h, w) < 6)
            {
                if (h < w)
                {
                    for (int j = 0; j < w; j++)
                    {
                        m[0][j] = '(';
                        m[h - 1][j] = ')';
                    }
                    for (int i = 1; i < h - 1; i++)
                    {
                        for (int j = 0; j < w; j++)
                        {
                            m[i][j] = ((i + j) % 2 == 1 ? '(' : ')');
                        }
                    }
                }
                else // w < h
                {
                    for (int i = 0; i < h; i++)
                    {
                        m[i][0] = '(';
                        m[i][w - 1] = ')';
                    }
                    for (int j = 1; j < w - 1; j++)
                    {
                        for (int i = 0; i < h; i++)
                        {
                            m[i][j] = ((i + j) % 2 == 1 ? '(' : ')');
                        }
                    }
                }
            }
            else
            {
                for (int i = 0; i < max(h, w); i++)
                {
                    m[i][0] = m[0][i] = '(';
                    m[i][w - 1] = m[h - 1][i] = ')';
                }
                for (int i = 1; i < h - 1; i++)
                {
                    for (int j = 1; j < w - 1; j++)
                    {
                        m[i][j] = ((i + j) % 2 == 1 ? ')' : '(');
                    }
                }
            }
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                printf("%c", m[i][j]);
            }
            puts("");
        }
    }
    return 0;
}