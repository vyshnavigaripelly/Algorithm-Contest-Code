#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, s, arr[105];
    memset(arr, 0x3f, sizeof(arr));
    arr[0] = 0;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        int hh, mm;
        cin >> hh >> mm;
        arr[i] = hh * 60 + mm;
    }
    if (arr[1] < s + 1)
    {
        for (int i = 1; i <= n + 1; i++)
        {
            if (arr[i] - arr[i - 1] >= 2 * s + 2)
            {
                int t = arr[i - 1] + s + 1;
                cout << t / 60 << ' ' << t % 60 << endl;
                break;
            }
        }
    }
    else
    {
        cout << "0 0" << endl;
    }
    return 0;
}
