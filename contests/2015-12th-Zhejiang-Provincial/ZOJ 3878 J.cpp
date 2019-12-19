#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    map<char, char> key;
    string qwerty = "~!@#$%^&*()_+`1234567890-=QWERTYUIOP{}|qwertyuiop[]\\ASDFGHJKL:\"asdfghjkl;'ZXCVBNM<>?zxcvbnm,./",
           dvorak = "~!@#$%^&*(){}`1234567890[]\"<>PYFGCRL?+|',.pyfgcrl/=\\AOEUIDHTNS_aoeuidhtns-:QJKXBMWVZ;qjkxbmwvz";
    for (int i = 0; i < qwerty.length(); i++)
    {
        key[qwerty[i]] = dvorak[i];
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
