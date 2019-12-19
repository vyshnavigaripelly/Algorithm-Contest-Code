#include <iostream>
#include <cstdlib>

using namespace std;

char s[] = "ULDR";

int main()
{
    for (int i = 1; i <= 50000; i++)
    {
        printf("%c", s[rand() % 4]);
    }
    return 0;
}