#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, flag = 0;
        cin >> n;
        while (n--)
        {
            int k;
            cin >> k;
            if (k <= 0)
            {
                flag = 1;
            }
        }
        if (flag)
        {
            cout << "Transform Mobility With Autonomous Driving" << endl;
        }
        else
        {
            cout << "WeRide.ai" << endl;
        }
    }
    return 0;
}