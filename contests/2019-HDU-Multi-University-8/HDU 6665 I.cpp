#include <iostream>
#include <algorithm>

using namespace std;

struct Point
{
    long long x, y;
    Point() {}
    Point(long long xx, long long yy) { x = xx, y = yy; }
};

struct Rect
{
    long long x1, y1, x2, y2;

    Rect() {}
    Rect(long long xx1, long long yy1, long long xx2, long long yy2) { x1 = xx1, y1 = yy1, x2 = xx2, y2 = yy2; }

    void input()
    {
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    }
} a, b;

int solve(const Rect &a, const Rect &b)
{
    if (a.x1 == b.x1 && a.y1 == b.y1 &&
        a.x2 == b.x2 && a.y2 == b.y2)
    {
        return 2;
    }
    Rect c = Rect(max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2));
    if (c.x1 < c.x2 && c.y1 < c.y2)
    {
        if (c.x1 == a.x1 && c.x2 == a.x2)
        {
            if (b.x1 <= a.x1 && b.x2 >= a.x2 && b.y1 <= a.y1 && b.y2 >= a.y2)
                return 3;
            int h = 0, v = 0;
            if (b.x1 < c.x1)
                h++;
            if (b.x2 > c.x2)
                h++;
            if (a.y1 < c.y1)
                v++;
            if (a.y2 > c.y2)
                v++;
            if ((b.y1 < a.y1 && a.y1 < b.y2 && b.y2 < a.y2) ||
                (a.y1 < b.y1 && b.y1 < a.y2 && a.y2 < b.y2))
                h = 1, v = 1;
            return h + v + 1 + 1;
        }
        else if (c.y1 == a.y1 && c.y2 == a.y2)
        {
            if (b.x1 <= a.x1 && b.x2 >= a.x2 && b.y1 <= a.y1 && b.y2 >= a.y2)
                return 3;
            int h = 0, v = 0;
            if (a.x1 < c.x1)
                h++;
            if (a.x2 > c.x2)
                h++;
            if (b.y1 < c.y1)
                v++;
            if (b.y2 > c.y2)
                v++;
            if ((b.x1 < a.x1 && a.x1 < b.x2 && b.x2 < a.x2) ||
                (a.x1 < b.x1 && b.x1 < a.x2 && a.x2 < b.x2))
                h = 1, v = 1;
            return h + v + 1 + 1;
        }
        else if (c.x2 - c.x1 != a.x2 - a.x1 && c.x2 - c.x1 != b.x2 - b.x1 &&
                 c.y2 - c.y1 != a.y2 - a.y1 && c.y2 - c.y1 != b.y2 - b.y1)
        {
            return 4;
        }
    }
    else
    {
        return 3;
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        a.input();
        b.input();
        printf("%d\n", max(solve(a, b), solve(b, a)));
    }
    return 0;
}