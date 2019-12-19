#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s[0] == 'S')
            cout << "Rock" << endl;
        else if (s[0] == 'R')
            cout << "Paper" << endl;
        else
            cout << "Scissors" << endl;
    }
    return 0;
}
