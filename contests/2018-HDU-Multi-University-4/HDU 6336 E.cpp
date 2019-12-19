#include <iostream>

using namespace std;

int M[10000][10000];
int A[15];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l;
        cin >> l;
        for (int i = 0; i < l; i++)
        {
            cin >> A[i];
        }
        int cursor = 0;
        for (int i = 0; i <= 200 * l; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                M[j][i - j] = A[cursor];
                cursor = (cursor + 1) % l;
            }
        }
        long long mid = 0;
        for (int i = 0; i < l * 2; i++)
        {
            for (int j = 0; j < l * 2; j++)
            {
                mid += M[i][j];
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            // x0,y0
            //       bx0,by0
            //               bx1,by1
            //                       x1,y1
            long long x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            long long bx0, by0, bx1, by1;
            bx0 = ((x0 + 1) / (2 * l) + ((x0 + 1) % (2 * l) == 0 ? 0 : 1)) * (2 * l);
            bx1 = ((x1 + 1) / (2 * l) - ((x1 + 1) % (2 * l) == 0 ? 1 : 0)) * (2 * l) - 1;
            by0 = ((y0 + 1) / (2 * l) + ((y0 + 1) % (2 * l) == 0 ? 0 : 1)) * (2 * l);
            by1 = ((y1 + 1) / (2 * l) - ((y1 + 1) % (2 * l) == 0 ? 1 : 0)) * (2 * l) - 1;
            long long ans = 0;
            if (x0 / (2 * l) == x1 / (2 * l) && y0 / (2 * l) == y1 / (2 * l))
            {
                for (int i = x0; i <= x1; i++)
                {
                    for (int j = y0; j <= y1; j++)
                    {
                        ans += M[i % (2 * l)][j % (2 * l)];
                    }
                }
            }
            else if (x0 / (2 * l) == x1 / (2 * l))
            {
                long long cnt = (by1 - by0 + 1) / (2 * l);
                long long left = 0, mid = 0, right = 0;
                for (int i = x0; i <= x1; i++)
                {
                    for (int j = 0; j < 2 * l; j++)
                    {
                        mid += M[i % (2 * l)][j];
                    }
                }
                for (int i = x0; i <= x1; i++)
                {
                    for (int j = y0; j < by0; j++)
                    {
                        left += M[i % (2 * l)][j % (2 * l)];
                    }
                    for (int j = by1 + 1; j <= y1; j++)
                    {
                        right += M[i % (2 * l)][j % (2 * l)];
                    }
                }
                ans = left + mid * cnt + right;
            }
            else if (y0 / (2 * l) == y1 / (2 * l))
            {
                long long cnt = (bx1 - bx0 + 1) / (2 * l);
                long long up = 0, mid = 0, down = 0;
                for (int i = y0; i <= y1; i++)
                {
                    for (int j = 0; j < 2 * l; j++)
                    {
                        mid += M[j][i % (2 * l)];
                    }
                }
                for (int i = y0; i <= y1; i++)
                {
                    for (int j = x0; j < bx0; j++)
                    {
                        up += M[j % (2 * l)][i % (2 * l)];
                    }
                    for (int j = bx1 + 1; j <= x1; j++)
                    {
                        down += M[j % (2 * l)][i % (2 * l)];
                    }
                }
                ans = up + mid * cnt + down;
            }
            else
            {
                long long summid = (bx1 - bx0 + 1) / (2 * l) * (by1 - by0 + 1) / (2 * l) * mid;
                long long left = 0, right = 0, up = 0, down = 0;
                for (long long i = x0; i < bx0; i++)
                {
                    for (int j = 0; j < 2 * l; j++)
                    {
                        up += M[i % (2 * l)][j];
                    }
                }
                up *= (by1 - by0 + 1) / (2 * l);
                for (long long i = bx1 + 1; i <= x1; i++)
                {
                    for (int j = 0; j < 2 * l; j++)
                    {
                        down += M[i % (2 * l)][j];
                    }
                }
                down *= (by1 - by0 + 1) / (2 * l);
                for (long long i = y0; i < by0; i++)
                {
                    for (int j = 0; j < 2 * l; j++)
                    {
                        left += M[j][i % (2 * l)];
                    }
                }
                left *= (bx1 - bx0 + 1) / (2 * l);
                for (long long i = by1 + 1; i <= y1; i++)
                {
                    for (int j = 0; j < 2 * l; j++)
                    {
                        right += M[j][i % (2 * l)];
                    }
                }
                right *= (bx1 - bx0 + 1) / (2 * l);
                long long upcorners = 0, downcorners = 0;
                for (int i = x0; i < bx0; i++)
                {
                    for (int j = y0; j < by0; j++)
                    {
                        upcorners += M[i % (2 * l)][j % (2 * l)];
                    }
                    for (int j = by1 + 1; j <= y1; j++)
                    {
                        upcorners += M[i % (2 * l)][j % (2 * l)];
                    }
                }
                for (int i = bx1 + 1; i <= x1; i++)
                {
                    for (int j = y0; j < by0; j++)
                    {
                        downcorners += M[i % (2 * l)][j % (2 * l)];
                    }
                    for (int j = by1 + 1; j <= y1; j++)
                    {
                        downcorners += M[i % (2 * l)][j % (2 * l)];
                    }
                }
                ans = summid + up + down + left + right + upcorners + downcorners;
            }
            cout << ans << endl;
        }
    }
    return 0;
}