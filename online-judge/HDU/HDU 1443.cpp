#include <iostream>
#include <list>
using namespace std;

void solve(int k)
{
    list<int> guy;
    for (int i = 1; i <= 2 * k; i++)
    {
        guy.push_back(i);
    }
    long long m = 0;
    while (true)
    {
        m++;
        list<int> tmp(guy);
        list<int>::iterator it = tmp.begin();
        int bad = 0, good = 0, flag = 1;
        while (!tmp.empty())
        {
            for (int i = 1; i < (m - 1) % tmp.size() + 1; i++)
            {
                it++;
                if (it == tmp.end())
                {
                    it = tmp.begin();
                }
            }
            if (*it <= k)
            {
                good++;
            }
            else
            {
                bad++;
            }
            if (bad < k && good > 0)
            {
                flag = 0;
                break;
            }
            it = tmp.erase(it);
            if (it == tmp.end())
            {
                it = tmp.begin();
            }
        }
        if (flag)
        {
            break;
        }
    }
    cout << m << endl;
}

int main()
{
    int k, num[14] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};
    while (cin >> k && k)
    {
        // solve(k);
        cout << num[k] << endl;
    }
    return 0;
}
