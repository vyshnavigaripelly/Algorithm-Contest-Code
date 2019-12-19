#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

#define random(a, b) ((a) + rand() % ((b) - (a) + 1))

const int N = 5e6 + 7;
int arr[N];

int main()
{
    int n;
    srand(time(NULL));
    while (~scanf("%d", &n))
    {
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 1; i <= 2000; i++)
        {
            int pos1 = random(1, n);
            int pos2 = random(1, n);
            int pos3 = random(1, n);
            if (pos1 != pos2 && pos2 != pos3 && pos3 != pos1)
            {
                long long a[3];
                a[0] = arr[pos1], a[1] = arr[pos2], a[2] = arr[pos3];
                sort(a, a + 3);
                if (a[0] + a[1] > a[2])
                {
                    flag = 1;
                }
            }
            if (flag)
            {
                break;
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
