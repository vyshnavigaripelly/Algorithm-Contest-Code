#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

map<string, int> order; // <name, id>
int tot = 0;

struct Node
{
    int rank;
    string name;
    long long solved, totaltime;
    long long time[20];
    int submission[20]; // <0 - not passed, =0 - ce/not submitted, >0 - ac
    int flag = 0;

    void output()
    {
        printf("%d \"%s\" %lld %lld\n", rank, name.c_str(), solved, totaltime);
        for (int i = 0; i < 15; i++)
        {
            printf("%c %lld %d\n", 'A' + i, time[i], submission[i]);
        }
    }
} arr[5007];

int main()
{
    int n;
    scanf("%d", &n);
    char s[500];
    int maxlen = 0;
    while (scanf("%s", s) && s[0] != 'G')
    {
        int h, m;
        char prob[2], name[500];
        sscanf(s, "%d:%d", &h, &m);
        scanf("%s", prob);
        int flag = 0;
        scanf("%s", s);
        if (s[0] == 'A')
        {
            flag = 1;
        }
        else if (s[0] != 'C')
        {
            flag = -1;
        }
        if (s[0] == 'W' || s[0] == 'C' || s[0] == 'R' || s[0] == 'P')
        {
            scanf("%*s");
        }
        else if (s[0] == 'T' || s[0] == 'M' || s[0] == 'O')
        {
            scanf("%*s%*s");
        }
        getchar();
        gets(name);
        maxlen = max(maxlen, (int)strlen(name));
        long long time = h * 60 + m;
        if (!order.count(name))
        {
            order[name] = tot;
            arr[tot].name = name;
            tot++;
        }
        int id = order[name], probid = prob[0] - 'A';
        if (arr[id].submission[probid] > 0)
        {
            continue;
        }
        if (flag == 1)
        {
            arr[id].submission[probid] = -arr[id].submission[probid] + 1;
            arr[id].time[probid] += time;
            arr[id].totaltime += arr[id].time[probid];
            arr[id].solved++;
        }
        else if (flag == -1)
        {
            arr[id].submission[probid]--;
            arr[id].time[probid] += 20;
        }
        if (flag != 0)
        {
            arr[id].flag = 1;
        }
    }
    sort(arr, arr + tot, [](const Node &a, const Node &b) {
        if (a.solved != b.solved)
            return a.solved > b.solved;
        else if (a.totaltime != b.totaltime)
            return a.totaltime < b.totaltime;
        return a.name < b.name;
    });
    arr[0].rank = 1;
    for (int i = 1; i < tot; i++)
    {
        if (arr[i].solved == arr[i - 1].solved && arr[i].totaltime == arr[i - 1].totaltime)
        {
            arr[i].rank = arr[i - 1].rank;
        }
        else
        {
            arr[i].rank = i + 1;
        }
    }
    printf("Rank  %*s  Solved  Penalty", -maxlen, "Who");
    for (int i = 0; i < n; i++)
    {
        printf("    %c", 'A' + i);
    }
    puts("");
    for (int i = 0; i < tot; i++)
    {
        if (arr[i].flag == 0)
        {
            continue;
        }
        printf("%4d  %*s  %6lld  %7lld", arr[i].rank, maxlen, arr[i].name.c_str(), arr[i].solved, arr[i].totaltime);
        for (int j = 0; j < n; j++)
        {
            int tmp = arr[i].submission[j];
            if (tmp < 0)
            {
                printf("%5d", tmp);
            }
            else if (tmp > 0)
            {
                char s[10] = "+";
                if (tmp > 1)
                {
                    s[1] = '0' + (tmp - 1);
                    s[2] = '\0';
                }
                printf("%5s", s);
            }
            else
            {
                printf("%5s", " ");
            }
        }
        puts("");
    }
    return 0;
}