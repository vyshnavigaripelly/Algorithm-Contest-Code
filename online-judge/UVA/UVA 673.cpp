#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        char ch;
        stack<char> s;
        while (ch = getchar())
        {
            if (ch == '\n')
            {
                break;
            }
            if (ch == '(' || ch == '[')
            {
                s.push(ch);
            }
            else if (!s.empty() && ((ch == ')' && s.top() == '(') || (ch == ']' && s.top() == '[')))
            {
                s.pop();
            }
            else if (ch == ')' || ch == ']')
            {
                s.push(ch);
            }
        }
        if (s.empty())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
