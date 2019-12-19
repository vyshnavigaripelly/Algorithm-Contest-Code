#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Student
{
    int idx;
    int correct;
    int h, m, s;
    int score, rank;
} stu[110];

bool cmpRank(Student &a, Student &b)
{
    if (a.correct != b.correct)
    {
        return a.correct > b.correct;
    }
    else if (a.h != b.h)
    {
        return a.h < b.h;
    }
    else if (a.m != b.m)
    {
        return a.m < b.m;
    }
    else
    {
        return a.s < b.s;
    }
}

bool cmpIdx(Student &a, Student &b)
{
    return a.idx < b.idx;
}

int main()
{
    int n;
    while (~scanf("%d", &n) && n > 0)
    {
        int cnt[6] = {0};
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d:%d:%d", &stu[i].correct, &stu[i].h, &stu[i].m, &stu[i].s);
            stu[i].idx = i;
            cnt[stu[i].correct]++;
        }
        sort(stu, stu + n, cmpRank);
        for (int i = 0; i < n; i++)
        {
            if (stu[i].correct == 5)
            {
                stu[i].score = 100;
            }
            else if (stu[i].correct == 0)
            {
                stu[i].score = 50;
            }
            else
            {
                int half = ((cnt[stu[i].correct] == 1) ? 1 : (cnt[stu[i].correct] / 2));
                int num = cnt[stu[i].correct];
                for (int j = 1; j <= num; j++)
                {
                    stu[i].score = 50 + 10 * stu[i].correct;
                    if (j <= half)
                    {
                        stu[i].score += 5;
                    }
                    i++;
                }
                i--;
            }
        }
        sort(stu, stu + n, cmpIdx);
        for (int i = 0; i < n; i++)
        {
            printf("%d\n", stu[i].score);
        }
        printf("\n");
    }
    return 0;
}
