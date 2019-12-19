#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int cube[25], cube2[25]; // top bottom front back left right
int arr[12][6][2] = {
    // top cw
    {
        {20, 15}, {6, 20}, {21, 6},
        {18, 16}, {5, 18}, {23, 5}
    },
    // top ccw
    {
        {15, 20}, {15, 21}, {21, 6},
        {16, 18}, {16, 23}, {23, 5}
    },
    // bottom cw
    {
        {19, 8}, {19, 13}, {13, 22},
        {17, 7}, {17, 14}, {14, 24}
    },
    // bottom ccw
    {
        {19, 13}, {19, 8}, {8, 22},
        {17, 14}, {17, 7}, {7, 24}        
    },
    // front cw
    {
        {3, 23}, {3, 19}, {19, 10},
        {4, 24}, {4, 20}, {20, 9}
    },
    // front ccw
    {
        {3, 19}, {3, 23}, {23, 10},
        {4, 20}, {4, 24}, {24, 9}
    },
    // back cw
    {
        {1, 21}, {1, 17}, {12, 17},
        {2, 22}, {2, 18}, {18, 11}
    },
    // back ccw
    {
        {1, 17}, {1, 21}, {21, 12},
        {2, 18}, {2, 22}, {22, 11}
    },
    // left cw
    {
        {1, 5}, {1, 13}, {13, 9},
        {3, 7}, {3, 15}, {15, 11}
    },
    // left ccw
    {
        {1, 13}, {1, 5}, {5, 9},
        {3, 15}, {3, 7}, {7, 11}
    },
    // right cw
    {
        {2, 14}, {2, 6}, {6, 10},
        {4, 16}, {4, 8}, {8, 12}
    },
    // right ccw
    {
        {2, 6}, {2, 14}, {14, 10},
        {4, 8}, {4, 16}, {16, 12}
    }
};

int check()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 2; j <= 4; j++)
        {
            if (cube2[i * 4 + j] != cube2[i * 4 + j - 1])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int cas;
    cin >> cas;
    while (cas--)
    {
        for (int i = 1; i <= 24; i++)
        {
            cin >> cube[i];
        }
        int flag = 0;
        for (int op = 0; op < 12; op++)
        {
            for (int i = 1; i <= 24; i++)
            {
                cube2[i] = cube[i];
            }
            if (check())
            {
                flag = 1;
                break;
            }
            for (int i = 0; i < 6; i++)
            {
                swap(cube2[arr[op][i][0]], cube2[arr[op][i][1]]);
            }
            if (check())
            {
                flag = 1;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}