#include <iostream>
using namespace std;

int main()
{
    string shengxiao[12] = {"rat", "ox", "tiger", "rabbit", "dragon", "snake",
                            "horse", "sheep", "monkey", "rooster", "dog", "pig"};
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int posa = 0, posb = 0;
        for (int i = 0; i < 12; i++)
        {
            if (a == shengxiao[i])
            {
                posa = i;
            }
            if (b == shengxiao[i])
            {
                posb = i;
            }
        }
        if (posb == posa)
        {
            cout << 12 << endl;
        }
        else if (posb > posa)
        {
            cout << posb - posa << endl;
        }
        else
        {
            cout << 12 - (posa - posb) << endl;
        }
    }
    return 0;
}
