#include <iostream>

using namespace std;

double arr[100007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &arr[i]);
            sum += arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            printf("%.6f ", (sum + k) * arr[i] / sum);
        }
        puts("");
    }
    return 0;
}