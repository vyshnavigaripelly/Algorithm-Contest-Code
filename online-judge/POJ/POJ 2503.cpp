#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

char a[15], b[15], input[50];

int main()
{
    map<string, string> dict;
    while (gets(input) && input[0] != '\0')
    {
        sscanf(input, "%s %s", a, b);
        dict[b] = a;
    }
    while (~scanf("%s", input))
    {
        map<string, string>::iterator it = dict.find(input);
        if (it != dict.end())
        {
            cout << it->second << endl;
        }
        else
        {
            puts("eh");
        }
    }
    return 0;
}
