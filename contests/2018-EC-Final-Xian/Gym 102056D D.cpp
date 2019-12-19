#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        puts(n <= m ? "Yes" : "No");
        for (int i = 0; i < n + m; i++)
        {
            int x;
            cin >> x;
        }
    }
    return 0;
}
