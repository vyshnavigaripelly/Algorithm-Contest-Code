#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int len = s.length(), sum = 0, k = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == 'O')
            {
                k++;
                sum += k;
            }
            else
            {
                k = 0;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
