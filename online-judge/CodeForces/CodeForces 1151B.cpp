#include <iostream>

using namespace std;

int arr[507][507];
int diff[507];

int main()
{
    int n, m;
    cin >> n >> m;
    int sum = 0, hasdiff = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != arr[i][0])
            {
                diff[i] = j;
                hasdiff = 1;
            }
        }
        sum ^= arr[i][0];
    }
    if (sum != 0)
    {
        cout << "TAK" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << 1 << ' ';
        }
    }
    else
    {
        if (hasdiff)
        {
            int flag = 0;
            cout << "TAK" << endl;
            for (int i = 0; i < n; i++)
            {
                if (!flag && diff[i] != 0)
                {
                    cout << diff[i] + 1 << ' ';
                    flag = 1;
                }
                else
                {
                    cout << 1 << ' ';
                }
            }
        }
        else
        {
            cout << "NIE" << endl;
        }
    }
    return 0;
}