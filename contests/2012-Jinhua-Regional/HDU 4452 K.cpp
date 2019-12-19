#include <iostream>
#include <algorithm>
using namespace std;

int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
char dirc[5] = "ENWS";

struct Rabbit
{
    int dir, speed, turn, x, y;
} rab[2];

int main()
{
    int n;
    while (cin >> n && n)
    {
        for (int i = 0; i < 2; i++)
        {
            char c;
            cin >> c >> rab[i].speed >> rab[i].turn;
            rab[i].dir = find(dirc, dirc + 4, c) - dirc;
        }
        rab[0].x = rab[0].y = 1;
        rab[1].x = rab[1].y = n;
        int k;
        cin >> k;
        for (int t = 1; t <= k; t++)
        {
            for (int i = 0; i < 2; i++)
            {
                rab[i].x += rab[i].speed * dir[rab[i].dir][0];
                rab[i].y += rab[i].speed * dir[rab[i].dir][1];
                if (rab[i].x > n)
                {
                    rab[i].x = n - (rab[i].x - n);
                    rab[i].dir = (rab[i].dir + 2) % 4;
                }
                if (rab[i].x < 1)
                {
                    rab[i].x = 1 + (1 - rab[i].x);
                    rab[i].dir = (rab[i].dir + 2) % 4;
                }
                if (rab[i].y > n)
                {
                    rab[i].y = n - (rab[i].y - n);
                    rab[i].dir = (rab[i].dir + 2) % 4;
                }
                if (rab[i].y < 1)
                {
                    rab[i].y = 1 + (1 - rab[i].y);
                    rab[i].dir = (rab[i].dir + 2) % 4;
                }
            }
            if (rab[0].x == rab[1].x && rab[0].y == rab[1].y)
            {
                swap(rab[0].dir, rab[1].dir);
            }
            else
            {
                for (int i = 0; i < 2; i++)
                {
                    if (t % rab[i].turn == 0)
                    {
                        rab[i].dir = (rab[i].dir + 1) % 4;
                    }
                }
            }
        }
        for (auto i : rab)
        {
            cout << i.x << ' ' << i.y << endl;
        }
    }
    return 0;
}