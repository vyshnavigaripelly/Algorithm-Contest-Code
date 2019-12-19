#include <iostream>

using namespace std;

int arr[50];

int ask(int n)
{
    cout << n << endl;
    fflush(stdout);
    int ret;
    cin >> ret;
    if (ret == 0 || ret == -2)
    {
        exit(0);
    }
    return ret;
}

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        arr[i] = ask(1);
    }
    int l = 1, r = m, cur = 0;
    while (l < r)
    {
        int mid = (l + r) >> 1, ans = ask(mid);
        if ((arr[cur] == 1 && ans == -1) || (arr[cur] != 1 && ans == 1))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
        cur = (cur + 1) % n;
    }
    ask(l);
    return 0;
}