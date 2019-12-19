#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;
const int maxp = 100;

int sgn(double x)
{
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}

inline double sqr(double x) { return x * x; }

struct Point
{
    double x, y;
    Point() {}
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    void input()
    {
        scanf("%lf%lf", &x, &y);
    }
    void output()
    {
        printf("%.2f %.2f\n", x, y);
    }
    bool operator==(Point b) const
    {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }

    bool operator<(Point b) const
    {
        return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
    }

    Point operator-(const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }

    double operator^(const Point &b) const
    {
        return x * b.y - y * b.x;
    }

    double operator*(const Point &b) const
    {
        return x * b.x + y * b.y;
    }

    double len()
    {
        return hypot(x, y);
    }

    double len2()
    {
        return x * x + y * y;
    }

    double distance(Point p)
    {
        return hypot(x - p.x, y - p.y);
    }

    Point operator+(const Point &b) const
    {
        return Point(x + b.x, y + b.y);
    }

    Point operator*(const double &k) const
    {
        return Point(x * k, y * k);
    }

    Point operator/(const double &k) const
    {
        return Point(x / k, y / k);
    }
};

struct polygon
{
    int n;
    Point p[maxp];
    void add(Point q)
    {
        p[n++] = q;
    }

    struct cmp
    {
        Point p;
        cmp(const Point &p0) { p = p0; }
        bool operator()(const Point &aa, const Point &bb)
        {
            Point a = aa, b = bb;
            int d = sgn((a - p) ^ (b - p));
            if (d == 0)
            {
                return sgn(a.distance(p) - b.distance(p)) < 0;
            }
            return d > 0;
        }
    };

    void norm()
    {
        Point mi = p[0];
        for (int i = 1; i < n; i++)
            mi = min(mi, p[i]);
        sort(p, p + n, cmp(mi));
    }

    void Graham(polygon &convex)
    {
        norm();
        int &top = convex.n;
        top = 0;
        if (n == 1)
        {
            top = 1;
            convex.p[0] = p[0];
            return;
        }
        if (n == 2)
        {
            top = 2;
            convex.p[0] = p[0];
            convex.p[1] = p[1];
            if (convex.p[0] == convex.p[1])
                top--;
            return;
        }
        convex.p[0] = p[0];
        convex.p[1] = p[1];
        top = 2;
        for (int i = 2; i < n; i++)
        {
            while (top > 1 && sgn((convex.p[top - 1] - convex.p[top - 2]) ^ (p[i] - convex.p[top - 2])) <= 0)
                top--;
            convex.p[top++] = p[i];
        }
        if (convex.n == 2 && (convex.p[0] == convex.p[1]))
            convex.n--;
    }
};

double ans[11] = {0, 0.00000000, 0.00000000, 3.00000000, 3.66671485, 4.16689780,
                  4.56689745, 4.90003490, 5.18563975, 5.43566605, 5.65836825};

void make()
{
    srand(time(0));
    int times = 2e7;
    for (int n = 3; n <= 6; n++)
    {
        long long cnt = 0;
        for (int i = 0; i < times; i++)
        {
            polygon pp = {0}, tmpp = {0};
            for (int j = 0; j < n; j++)
            {
                double x, y;
                while (true)
                {
                    x = rand();
                    y = rand();
                    if (x + y <= 16000)
                    {
                        break;
                    }
                }
                Point t = Point(x, y);
                pp.add(t);
            }
            pp.Graham(tmpp);
            cnt += tmpp.n;
            if (i && i % (int)1e6 == 0)
            {
                printf("+");
            }
        }
        double tmp = 1.0 * cnt / times;
        printf(" ** %lld %.8f\n", cnt, tmp);
        ans[n] = tmp;
    }
    for (int i = 1; i <= 10; i++)
    {
        printf("%.8f,", ans[i]);
    }
}

int main()
{
#ifdef WEGFAN
    make();
#endif
    int n;
    scanf("%*d %*d %*d %*d %*d %*d %d", &n);
    printf("%.8f\n", ans[n]);
    return 0;
}