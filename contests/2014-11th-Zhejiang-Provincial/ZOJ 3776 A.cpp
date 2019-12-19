#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int sum1 = 0, sum2 = 0;
        int k;
        while (n--)
        {
            cin >> k;
            sum1 += k;
        }
        while (m--)
        {
            cin >> k;
            sum2 += k;
        }
        if (sum1 == sum2)
        {
            cout << "Draw" << endl;
        }
        else
        {
            cout << (sum1 > sum2 ? "Calem" : "Serena") << endl;
        }
    }
    return 0;
}