#include <iostream>
#include <algorithm>
using namespace std;

struct Rect
{
    int w, h;
} arr[112345];

int main()
{
    int n, flag = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].w >> arr[i].h;
        if (arr[i].w > arr[i].h)
        {
            swap(arr[i].w, arr[i].h);
        }
    }
    if (n == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (arr[i].h > arr[i - 1].h)
            {
                swap(arr[i].w, arr[i].h);
                if (arr[i].h > arr[i - 1].h)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}