#include <iostream>
#include <set>
using namespace std;

int main()
{
    int cas;
    while (cin >> cas && cas != -1)
    {
        string a, b;
        cin >> a >> b;
        set<char> guess, ans;
        for (char k : a)
        {
            ans.insert(k);
        }
        int wrong = 0;
        for (char k : b)
        {
            if (ans.count(k) == 1)
            {
                ans.erase(k);
            }
            else
            {
                wrong++;
            }
            if (ans.empty() || wrong == 7)
            {
                break;
            }
        }
        cout << "Round " << cas << endl;
        if (ans.empty() && wrong < 7)
        {
            cout << "You win." << endl;
        }
        else if (wrong >= 7)
        {
            cout << "You lose." << endl;
        }
        else
        {
            cout << "You chickened out." << endl;
        }
    }
    return 0;
}
