#include <iostream>
using namespace std;

int Check(int n, int r)
{
    int sum = 0;
    do
    {
        sum += n % r;
        n /= r;
    } while (n != 0);
    return sum;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        int r = Check(n, 10);
        if (Check(n, 16) == r && Check(n, 12) == r)
        {
            cout << n << " is a Sky Number." << endl;
        }
        else
        {
            cout << n << " is not a Sky Number." << endl;
        }
    }
    return 0;
}
