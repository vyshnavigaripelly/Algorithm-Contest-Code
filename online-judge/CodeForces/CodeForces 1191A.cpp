#include <iostream>

using namespace std;

int calc(int n)
{
    if (n % 4 == 1)
        return 0;
    else if (n % 4 == 3)
        return 1;
    else if (n % 4 == 2)
        return 2;
    else
        return 3;
}

int main()
{
    int n;
    cin >> n;
    int minn = calc(n), mini = 0;
    for (int i = 1; i <= 2; i++)
    {
        if (calc(n + i) < minn)
        {
            minn = calc(n + i);
            mini = i;
        }
    }
    cout << mini << ' ' << (char)('A' + minn) << endl;
    return 0;
}