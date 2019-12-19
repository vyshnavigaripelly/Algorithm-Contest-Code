#include <iostream>

using namespace std;

int arr[5][5], ans[5][2];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> arr[i][j];
            }
        }
        if (arr[0][0] == 1 || arr[0][0] == 2)
        {
            ans[0][0] = 2;
        }
        else
        {
            ans[0][0] = arr[0][0];
        }
        ans[0][1] = arr[0][ans[0][0]];
        if (arr[1][0] == 1)
        {
            for (int i = 1; i < 5; i++)
            {
                if (arr[1][i] == 4)
                {
                    ans[1][0] = i;
                    break;
                }
            }
        }
        else if (arr[1][0] == 3)
        {
            ans[1][0] = 1;
        }
        else
        {
            ans[1][0] = ans[0][0];
        }
        ans[1][1] = arr[1][ans[1][0]];
        if (arr[2][0] == 1)
        {
            for (int i = 1; i < 5; i++)
            {
                if (arr[2][i] == ans[1][1])
                {
                    ans[2][0] = i;
                    break;
                }
            }
        }
        else if (arr[2][0] == 2)
        {
            for (int i = 1; i < 5; i++)
            {
                if (arr[2][i] == ans[0][1])
                {
                    ans[2][0] = i;
                    break;
                }
            }
        }
        else if (arr[2][0] == 3)
        {
            ans[2][0] = 3;
        }
        else if (arr[2][0] == 4)
        {
            for (int i = 1; i < 5; i++)
            {
                if (arr[2][i] == 4)
                {
                    ans[2][0] = i;
                    break;
                }
            }
        }
        ans[2][1] = arr[2][ans[2][0]];
        if (arr[3][0] == 1)
        {
            ans[3][0] = ans[0][0];
        }
        else if (arr[3][0] == 2)
        {
            ans[3][0] = 1;
        }
        else
        {
            ans[3][0] = ans[1][0];
        }
        ans[3][1] = arr[3][ans[3][0]];
        if (arr[4][0] == 3)
        {
            for (int i = 1; i < 5; i++)
            {
                if (arr[4][i] == ans[3][1])
                {
                    ans[4][0] = i;
                    break;
                }
            }
        }
        else if (arr[4][0] == 4)
        {
            for (int i = 1; i < 5; i++)
            {
                if (arr[4][i] == ans[2][1])
                {
                    ans[4][0] = i;
                    break;
                }
            }
        }
        else
        {
            for (int i = 1; i < 5; i++)
            {
                if (arr[4][i] == ans[arr[4][0] - 1][1])
                {
                    ans[4][0] = i;
                    break;
                }
            }
        }
        ans[4][1] = arr[4][ans[4][0]];
        for (int i = 0; i < 5; i++)
        {
            cout << ans[i][0] << ' ' << ans[i][1] << endl;
        }
    }
    return 0;
}