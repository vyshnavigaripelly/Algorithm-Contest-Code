#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char str[100007];
long long arr[20];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(arr, 0, sizeof(arr));
        scanf("%s", str);
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            arr[0] += str[i] - '0';
        }
        int cnt = 1;
        while (arr[cnt - 1] >= 10)
        {
            long long k = arr[cnt - 1];
            while (k > 0)
            {
                arr[cnt] += k % 10;
                k /= 10;
            }
            cnt++;
        }
        int sum = (str[len - 1] - '0') % 2 == 0;
        for (int i = 0; i < cnt; i++)
        {
            sum += arr[i] % 2 == 0;
        }
        if (len == 1 || sum == cnt + 1 || sum == 0)
        {
            puts("2");
        }
        else
        {
            puts("3");
        }
    }
    return 0;
}