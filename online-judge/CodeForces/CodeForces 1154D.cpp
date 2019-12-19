#include <iostream>
#include <algorithm>

using namespace std;

int arr[200007];

int main()
{

    int n, b, a, aa, pos = 0;
    cin >> n >> b >> a;
    aa = a;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    while (b + aa > 0)
    {
        if (arr[pos] == 0)
        {
            if (aa > 0)
            {
                aa--;
            }
            else
            {
                b--;
            }
        }
        else
        {
            if (b > 0)
            {
                if (aa + 1 > a)
                {
                    aa--;
                }
                else
                {
                    aa = min(aa + 1, a);
                    b--;
                }
            }
            else
            {
                aa--;
            }
        }
        pos++;
        if (pos > n)
        {
            break;
        }
    }
    cout << min(pos, n) << endl;
    return 0;
}