#include <iostream>
#include <string>
#include <list>
using namespace std;

int n;
list<int> block[30];

void findpos(int k, int &c, list<int>::iterator &it)
{
    for (c = 0; c < n; c++)
    {
        for (it = block[c].begin(); it != block[c].end(); it++)
        {
            if (*it == k)
            {
                return;
            }
        }
    }
}

void clearblocks(int c, list<int>::iterator it) // return block *it and above to original pos
{
    for (list<int>::iterator itcpy = it; itcpy != block[c].end(); itcpy++)
    {
        int val = *itcpy;
        block[val].push_back(val);
    }
    block[c].erase(it, block[c].end());
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        block[i].push_back(i);
    }
    string s1, s2;
    int a, b;
    while (cin >> s1)
    {
        if (s1 == "quit")
        {
            break;
        }
        cin >> a >> s2 >> b;
        int ca, cb;
        list<int>::iterator ita, itb;
        findpos(a, ca, ita);
        findpos(b, cb, itb);
        if (ca == cb) // illegal command
        {
            continue;
        }
        if (s1 == "move")
        {
            if (s2 == "onto")
            {
                clearblocks(ca, ++ita);
                clearblocks(cb, ++itb);
                block[cb].push_back(block[ca].back());
                block[ca].pop_back();
            }
            else // over
            {
                clearblocks(ca, ++ita);
                block[cb].push_back(block[ca].back());
                block[ca].pop_back();
            }
        }
        else // pile
        {
            if (s2 == "onto")
            {
                clearblocks(cb, ++itb);
                block[cb].insert(block[cb].end(), ita, block[ca].end());
                block[ca].erase(ita, block[ca].end());
            }
            else // over
            {
                block[cb].insert(block[cb].end(), ita, block[ca].end());
                block[ca].erase(ita, block[ca].end());
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        for (int k : block[i])
        {
            cout << " " << k;
        }
        cout << endl;
    }
    return 0;
}