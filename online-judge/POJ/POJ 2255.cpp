#include <iostream>
#include <string>
using namespace std;

string pre, in;
int cur = 0;

void dfs(int begin, int end)
{
    int pos = in.find(pre[cur]);
    cur++;
    if (pos - begin > 0) // left sub-tree
    {
        dfs(begin, pos - 1);
    }
    if (end - pos > 0) // right sub-tree
    {
        dfs(pos + 1, end);
    }
    cout << in[pos];
}

int main()
{
    while (cin >> pre >> in)
    {
        cur = 0;
        int len = pre.length();
        dfs(0, len - 1);
        cout << endl;
    }
    return 0;
}