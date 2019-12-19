#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string x, op[100];
    int num[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> op[i] >> num[i];
    }
    int ans = 1;
    for (double i = -5; i <= 1005; i += 0.5)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (op[j] == "=" && i == num[j])
            {
                cnt++;
            }
            else if (op[j] == "<=" && i <= num[j])
            {
                cnt++;
            }
            else if (op[j] == ">=" && i >= num[j])
            {
                cnt++;
            }
            else if (op[j] == "<" && i < num[j])
            {
                cnt++;
            }
            else if (op[j] == ">" && i > num[j])
            {
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}