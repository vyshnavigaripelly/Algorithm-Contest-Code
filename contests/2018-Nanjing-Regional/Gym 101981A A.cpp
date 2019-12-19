#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if (n == 0)
    {
        cout << "Austin" << endl;
    }
    else if (k != 1)
    {
        cout << "Adrien" << endl;
    }
    else
    {
        cout << (n % 2 == 0 ? "Austin" : "Adrien") << endl;
    }
    return 0;
}