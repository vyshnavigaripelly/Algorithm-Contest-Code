#include <iostream>
using namespace std;

int main()
{
    int pearls = 0, links = 0;
    string s;
    cin >> s;
    for (char k : s)
    {
        if (k == 'o')
        {
            pearls++;
        }
        else if (k == '-')
        {
            links++;
        }
    }
    if (links == 0 || pearls == 0 || links % pearls == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
