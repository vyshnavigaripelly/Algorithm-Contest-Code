#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long sum = 0, k = 0;
    for (int i = 1;; i++)
    {
        if (sum + i > n)
        {
            k = i - 1;
            break;
        }
        sum += i;
    }
    cout << "A";
    for (int i = k; i >= 1; i--)
    {
        if (i == n - sum)
        {
            cout << "H";
        }
        cout << "HU";
    }
    cout << "ICPC" << endl;
    return 0;
}