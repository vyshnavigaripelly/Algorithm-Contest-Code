#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    string input;
    while (getline(cin, input) && input != "ENDOFINPUT")
    {
        if (input != "START" && input != "END")
        {
            for (char ch : input)
            {
                if (isupper(ch))
                {
                    cout << (char)((ch - 'A' + 21) % 26 + 'A');
                }
                else
                {
                    cout << ch;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
