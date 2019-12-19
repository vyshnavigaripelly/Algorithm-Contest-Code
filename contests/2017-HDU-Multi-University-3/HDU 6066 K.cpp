#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    while (n--)
    {
        int k;
        cin >> k;
        cnt += (k <= 35);
    }
    cout << cnt << endl;
    return 0;
}