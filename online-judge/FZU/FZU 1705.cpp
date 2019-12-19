#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int arr[233] = {0};
        while (n--)
        {
            int k;
            cin >> k;
            arr[k + 100]++;
        }
        int maxn = 0, maxpos = -100;
        for (int i = 0; i <= 200; i++)
        {
            if (arr[i] > maxn)
            {
                maxn = arr[i];
                maxpos = i - 100;
            }
        }
        cout << maxpos << " " << maxn << endl;
    }
    return 0;
}
