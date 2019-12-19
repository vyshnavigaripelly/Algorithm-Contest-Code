#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    map<char, char> key;
    string wrong = "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./",
           correct = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
    for (int i = 0; i < wrong.length(); i++)
    {
        key[wrong[i]] = correct[i];
    }
    char ch;
    while ((ch = getchar()) != EOF)
    {
        if (key.count(ch) == 1)
        {
            cout << key[ch];
        }
        else
        {
            cout << ch;
        }
    }
    return 0;
}
