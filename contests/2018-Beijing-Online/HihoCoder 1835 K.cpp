#include <iostream>

using namespace std;

const int N = 107;

int c[N], s[N], arr[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k, r;
        scanf("%d %d %d", &n, &k, &r);
        for (int i = 1; i <= k; i++)
        {
            scanf("%d", &c[i]);
        }
        while (n--)
        {
            for (int i = 1; i <= k; i++)
            {
                scanf("%d", &s[i]);
                arr[i] = abs(s[i] - c[i]);
            }
            double ansl = 0, ansr = 1007, ansm;
            while (ansr - ansl > 1e-8)
            {
                ansm = (ansl + ansr) / 2;
                double sum = 0;
                for (int i = 1; i <= k; i++)
                {
                    sum += max(0.0, arr[i] - ansm);
                }
                if (sum <= r)
                    ansr = ansm;
                else
                    ansl = ansm;
            }
            for (int i = 1; i <= k; i++)
            {
                if (s[i] > c[i])
                {
                    printf("%.4f ", s[i] - min(1.0 * arr[i], ansl));
                }
                else
                {
                    printf("%.4f ", s[i] + min(1.0 * arr[i], ansl));
                }
            }
            puts("");
        }
    }
    return 0;
}