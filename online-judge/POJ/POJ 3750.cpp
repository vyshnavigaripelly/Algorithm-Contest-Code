#include <iostream>
#include <cstdio>
#include <list>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string name;
    list<string> children;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        children.push_back(name);
    }
    int w, s;
    scanf("%d,%d", &w, &s);
    list<string>::iterator it = children.begin();
    advance(it, w - 1);
    while (!children.empty())
    {
        for (int i = 1; i < s; i++)
        {
            it++;
            if (it == children.end())
            {
                it = children.begin();
            }
        }
        cout << *it << endl;
        it = children.erase(it);
        if (it == children.end())
        {
            it = children.begin();
        }
    }
    return 0;
}
