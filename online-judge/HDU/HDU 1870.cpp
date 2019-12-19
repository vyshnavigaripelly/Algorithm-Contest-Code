#include <iostream>
using namespace std;

int main()
{
    string in;
    while (cin >> in)
    {
        int cnt = 0;
        for (int i = 0; i < in.length(); i++)
        {
            if (in[i] == '(')
            {
                cnt++;
            }
            else if (in[i] == ')')
            {
                cnt--;
            }
            else if (in[i] == 'B')
            {
                break;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
