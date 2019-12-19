#include <iostream>
using namespace std;

int main()
{
    int a[25] = {1, 3, 7};
    for (int i = 3; i <= 20; i++)
    {
        a[i] = 2 * a[i - 1] + a[i - 2];
    }
    int c;
    cin >> c;
    while (c--)
    {
        int n;
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}
