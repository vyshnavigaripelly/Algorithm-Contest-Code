#include <iostream>
using namespace std;

int finger[100007], glove[100007];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> finger[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> glove[i];
        }
        int front = 1, back = 1;
        for (int i = 0; i < n; i++)
        {
            if (finger[i] > glove[i])
            {
                front = 0;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (finger[i] > glove[n - i - 1])
            {
                back = 0;
                break;
            }
        }
        if (front && back)
        {
            cout << "both" << endl;
        }
        else if (front)
        {
            cout << "front" << endl;
        }
        else if (back)
        {
            cout << "back" << endl;
        }
        else
        {
            cout << "none" << endl;
        }
    }
    return 0;
}