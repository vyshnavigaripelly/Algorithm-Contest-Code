#include <iostream>
#include <algorithm>

using namespace std;

int arr[7] = {0, 1, 2, 0, 2, 1, 0};

int main()
{
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    int w = min({a / 3, b / 2, c / 2});
    for (int d = 0; d < 7; d++)
    {
        int A[3] = {a - w * 3, b - w * 2, c - w * 2};
        for (int i = 0; i < 7; i++)
        {
            ans = max(ans, w * 7 + i);
            A[arr[(d + i) % 7]]--;
            if (A[arr[(d + i) % 7]] == -1)
            {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}