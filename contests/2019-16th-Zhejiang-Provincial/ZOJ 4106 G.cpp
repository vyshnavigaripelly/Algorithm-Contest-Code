#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        while (true)
        {
            if (num % 7 == 0 && num % 4 != 0)
            {
                cout << num << endl;
                break;
            }
            num++;
        }
    }
    return 0;
}
