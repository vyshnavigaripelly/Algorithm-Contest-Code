#include <iostream>
using namespace std;

int arr[50][50];
string s = "+-*/";

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int r = 0, c = 0, cnt = 0;
        while (cnt < (1 + n) * n / 2)
        {
            while (r + 1 < n)
            {
                arr[r][c] = cnt;
                cnt++;
                r++;
                c++;
            }
            arr[r][c] = cnt;
            cnt++;
            c--;
            while (c > 0)
            {
                arr[r][c] = cnt;
                cnt++;
                r--;
                c--;
            }
            arr[r][c] = cnt;
            cnt++;
            r++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << s[arr[i][j] % 4] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
