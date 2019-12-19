#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, max = 0, min = 0;
        cin >> a >> b >> c;
        int total = a + b + c, combo = 0;
        for (int i = 0; i < a; i++)
        {
            min += 300 * (combo * 2 + 1);
            combo++;
        }
        for (int i = 0; i < b; i++)
        {
            min += 100 * (combo * 2 + 1);
            combo++;
        }
        for (int i = 0; i < c; i++)
        {
            min += 50 * (combo * 2 + 1);
            combo++;
        }
        combo = 0;
        for (int i = 0; i < c; i++)
        {
            max += 50 * (combo * 2 + 1);
            combo++;
        }
        for (int i = 0; i < b; i++)
        {
            max += 100 * (combo * 2 + 1);
            combo++;
        }
        for (int i = 0; i < a; i++)
        {
            max += 300 * (combo * 2 + 1);
            combo++;
        }
        cout << min << " " << max << endl;
    }
    return 0;
}
