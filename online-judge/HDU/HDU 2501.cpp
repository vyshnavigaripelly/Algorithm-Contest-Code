#include <iostream>
using namespace std;

int main()
{
    int a[35] = {1, 3, 5};
    for (int i = 3; i < 35; i++)
    {
        a[i] = 2 * a[i - 2] + a[i - 1];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << a[n - 1] << endl;
    }
    return 0;
}
