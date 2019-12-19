#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char name[100];
        cin >> name;
        for (int i = 0; name[i] != '\0'; i++)
            name[i] = toupper(name[i]);
        if (!strcmp(name, "JESSIE"))
            cout << "Good guy!" << endl;
        else
            cout << "Dare you say that again?" << endl;
    }

    return 0;
}
