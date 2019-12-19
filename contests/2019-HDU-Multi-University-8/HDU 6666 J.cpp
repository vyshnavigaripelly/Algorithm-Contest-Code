#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Node
{
    int id;
    char name[20];
    long long num, time;
} arr[100007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, d;
        scanf("%d %d", &n, &d);
        for (int i = 0; i < n; i++)
        {
            arr[i].id = i;
            scanf("%s %lld %lld", arr[i].name, &arr[i].num, &arr[i].time);
        }
        sort(arr, arr + n, [](const Node &a, const Node &b) {
            return a.num != b.num ? a.num > b.num : a.time < b.time;
        });
        if (n * d % 10 == 5)
        {
            puts(arr[n * d / 10].name);
        }
        else
        {
            puts("Quailty is very great");
        }
    }
    return 0;
}