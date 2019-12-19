#include <iostream>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int k : {100, 20, 10, 5, 1})
    {
        cnt += n / k;
        n %= k;
    }
    cout << cnt << endl;
    return 0;
}