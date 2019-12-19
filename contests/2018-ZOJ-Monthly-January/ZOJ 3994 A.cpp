#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            ans1 += k;
        }
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            ans2 += k;
        }
        cout << (ans1 > ans2 ? "BaoBao" : "DreamGrid") << endl;
    }
    return 0;
}