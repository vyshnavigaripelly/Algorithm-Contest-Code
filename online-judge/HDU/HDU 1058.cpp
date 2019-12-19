#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2000000007;

long long arr[6000];

int main()
{
    long long ans, cnt = 1;
    for (int two = 0; two <= 32; two++)
    {
        ans = pow(2, two);
        if (ans > maxn)
        {
            break;
        }
        for (int three = 0; three <= 20; three++)
        {
            ans = pow(2, two) * pow(3, three);
            if (ans > maxn)
            {
                break;
            }
            for (int five = 0; five <= 14; five++)
            {
                ans = pow(2, two) * pow(3, three) * pow(5, five);
                if (ans > maxn)
                {
                    break;
                }
                for (int seven = 0; seven <= 12; seven++)
                {
                    ans = pow(2, two) * pow(3, three) * pow(5, five) * pow(7, seven);
                    if (ans > maxn)
                    {
                        break;
                    }
                    arr[cnt++] = ans;
                }
            }
        }
    }
    sort(arr + 1, arr + cnt);
    int n;
    while (~scanf("%d", &n) && n)
    {
        string s;
        if (n % 100 != 11 && n % 10 == 1)
        {
            s = "st";
        }
        else if (n % 100 != 12 && n % 10 == 2)
        {
            s = "nd";
        }
        else if (n % 100 != 13 && n % 10 == 3)
        {
            s = "rd";
        }
        else
        {
            s = "th";
        }
        printf("The %d%s humble number is %lld.\n", n, s.c_str(), arr[n]);
    }
    return 0;
}