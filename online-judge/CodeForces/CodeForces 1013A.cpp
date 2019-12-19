#include <iostream>
#include <numeric>
using namespace std;

int a[1007], b[1007];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout << (accumulate(a, a + n, 0) >= accumulate(b, b + n, 0) ? "Yes" : "No") << endl;
    return 0;
}