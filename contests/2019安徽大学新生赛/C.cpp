#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n % 2 == 1)
    {
        cout << "AHUICPC" << string(n - 1, 'C') << endl;
    }
    else
    {
        cout << string(n / 2 - 1, 'A') << "AHUICPCC" << endl;
    }
    return 0;
}