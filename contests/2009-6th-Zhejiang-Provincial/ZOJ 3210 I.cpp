#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int in[150], out[150];
        for (int i = 0; i < n; i++)
        {
            cin >> in[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> out[i];
        }
        int flag1 = 1, flag2 = 1;
        for (int i = 0; i < n; i++)
        {
            if (in[i] != out[i])
            {
                flag1 = 0;
                break;
            }
        }
        reverse(out, out + n);
        for (int i = 0; i < n; i++)
        {
            if (in[i] != out[i])
            {
                flag2 = 0;
                break;
            }
        }
        if (flag1)
        {
            if (flag2)
            {
                cout << "both" << endl;
            }
            else
            {
                cout << "queue" << endl;
            }
        }
        else
        {
            if (flag2)
            {
                cout << "stack" << endl;
            }
            else
            {
                cout << "neither" << endl;
            }
        }
    }
    return 0;
}
