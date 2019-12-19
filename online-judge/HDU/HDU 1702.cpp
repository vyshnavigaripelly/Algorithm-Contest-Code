#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        string f;
        cin >> m >> f;
        if (f == "FIFO")
        {
            queue<int> qu;
            while (m--)
            {
                string k;
                int n;
                cin >> k;
                if (k == "IN")
                {
                    cin >> n;
                    qu.push(n);
                }
                else if (k == "OUT")
                {
                    if (!qu.empty())
                    {
                        cout << qu.front() << endl;
                        qu.pop();
                    }
                    else
                    {
                        cout << "None" << endl;
                    }
                }
            }
        }
        else
        {
            stack<int> st;
            while (m--)
            {
                string k;
                int n;
                cin >> k;
                if (k == "IN")
                {
                    cin >> n;
                    st.push(n);
                }
                else if (k == "OUT")
                {
                    if (!st.empty())
                    {
                        cout << st.top() << endl;
                        st.pop();
                    }
                    else
                    {
                        cout << "None" << endl;
                    }
                }
            }
        }
    }
    return 0;
}
