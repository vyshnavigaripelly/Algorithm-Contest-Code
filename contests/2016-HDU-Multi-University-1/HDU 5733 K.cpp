#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const double eps = 1e-8;

int sgn(double x)
{
    if (fabs(x) < eps)
        return 0;
    return (x < 0) ? -1 : 1;
}

struct Point
{
    double x, y, z;

    Point() {}
    Point(double xx, double yy, double zz) { x = xx, y = yy, z = zz; }

    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y, z + b.z); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y, z - b.z); }
    Point operator*(const double &b) const { return Point(x * b, y * b, z * b); }
    Point operator/(const double &b) const { return Point(x / b, y / b, z / b); }
    double operator*(const Point &b) const { return x * b.x + y * b.y + z * b.z; }
    Point operator^(const Point &b) const { return Point(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x); }

    int input() { return scanf("%lf %lf %lf", &x, &y, &z); }
    void output() { printf("(%f, %f, %f)\n", x, y, z); }
    double len() { return sqrt(x * x + y * y + z * z); }
};

struct Plane
{
    Point a, b, c, o;

    Plane() {}
    Plane(Point aa, Point bb, Point cc) { a = aa, b = bb, c = cc, o = pvec(); }

    Point pvec() { return (b - a) ^ (c - a); }
    bool pointonplane(Point p) { return sgn((p - a) * o) == 0; }
};

struct Matrix
{
    static const int N = 4;

    double a[N][N];

    double det()
    {
        double ans = 0;
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                vector<double> mat[3];
                int now = 0;
                for (int i = 0; i < 4; i++)
                {
                    if (i == r)
                        continue;
                    for (int j = 0; j < 4; j++)
                    {
                        if (j == c)
                            continue;
                        mat[now].push_back(a[i][j]);
                    }
                    now++;
                }
                double tmp = ((r + c) % 2 == 1 ? -1 : 1) * (mat[1 - 1][0] * mat[2 - 1][1] * mat[3 - 1][2] + mat[1 - 1][1] * mat[2 - 1][2] * mat[3 - 1][0] + mat[1 - 1][2] * mat[2 - 1][0] * mat[3 - 1][1] - mat[3 - 1][0] * mat[2 - 1][1] * mat[1 - 1][2] - mat[3 - 1][1] * mat[2 - 1][2] * mat[1 - 1][0] - mat[3 - 1][2] * mat[2 - 1][0] * mat[1 - 1][1]);
                ans += tmp;
            }
        }
        return fabs(ans);
    }
};

int main()
{
    Point a, b, c, d;
    while (~a.input() && b.input() && c.input() && d.input())
    {
        if (Plane(a, b, c).pointonplane(d))
        {
            puts("O O O O");
            continue;
        }
        Point center = (d * ((b - a) ^ (c - a)).len() +
                        c * ((b - a) ^ (d - a)).len() +
                        b * ((c - a) ^ (d - a)).len() +
                        a * ((c - b) ^ (d - b)).len()) /
                       (((b - a) ^ (c - a)).len() +
                        ((b - a) ^ (d - a)).len() +
                        ((c - a) ^ (d - a)).len() +
                        ((c - b) ^ (d - b)).len());
        Matrix tmp = {{{a.x, a.y, a.z, 1},
                       {b.x, b.y, b.z, 1},
                       {c.x, c.y, c.z, 1},
                       {d.x, d.y, d.z, 1}}};
        double radius = tmp.det() /
                        (((b - a) ^ (c - a)).len() +
                         ((b - a) ^ (d - a)).len() +
                         ((c - a) ^ (d - a)).len() +
                         ((c - b) ^ (d - b)).len());
        printf("%.4f %.4f %.4f %.4f\n", center.x, center.y, center.z, radius);
    }
    return 0;
}