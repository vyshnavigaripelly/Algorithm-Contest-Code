#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        string s;
        while (n)
        {
            n--;
            s += n % 26 + 'A';
            n /= 26;
        }
        cout << string(s.rbegin(), s.rend()) << endl;
    }
    return 0;
}
