#include <iostream>

using namespace std;

int arr[107][107];
int score[107], ball[107];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
            ball[i] += arr[i][j];
            ball[j] -= arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > arr[j][i])
            {
                score[i] += 3;
            }
            else if (arr[i][j] < arr[j][i])
            {
                score[j] += 3;
            }
            else
            {
                score[i]++;
                score[j]++;
            }
        }
    }
    int pos = 0, flag = 0;
    for (int i = 1; i < n; i++)
    {
        if (score[i] > score[pos])
        {
            pos = i;
            flag = 0;
        }
        else if (score[i] == score[pos])
        {
            if (ball[i] == ball[pos])
            {
                flag = 1;
            }
            else if (ball[i] > ball[pos])
            {
                pos = i;
                flag = 0;
            }
        }
    }
    if (flag)
    {
        puts("play-offs");
    }
    else
    {
        printf("%d\n", pos + 1);
    }
    return 0;
}