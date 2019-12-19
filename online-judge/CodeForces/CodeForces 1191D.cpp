#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

long long arr[100007];
map<long long, long long> mp;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int flag = 1;
    if (mp.count(0) && mp[0] > 1)
    {
        flag = 0;
    }
    for (auto i : mp)
    {
        if (i.second > 2)
        {
            flag = 0;
        }
    }
    int tmp = 0;
    for (auto i : mp)
    {
        if (i.second > 1)
            tmp++;
    }
    if (tmp >= 2)
    {
        flag = 0;
    }
    for (auto i : mp)
    {
        if (i.second > 1 && mp.count(i.first - 1) && mp[i.first - 1] > 0)
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        puts("cslnb");
    }
    else
    {
        sort(arr, arr + n);
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i] - i;
        }
        if (sum % 2 == 1)
            puts("sjfnb");
        else
            puts("cslnb");
    }
    return 0;
}