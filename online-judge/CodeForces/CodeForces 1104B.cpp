#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> st;

int main()
{
    string s;
    cin >> s;
    int cnt = 0, i = 0;
    st.push('#');
    for (int i = 0; i < s.length(); i++)
    {
        if (st.top() == s[i])
        {
            st.pop();
            cnt++;
        }
        else
        {
            st.push(s[i]);
        }
    }
    cout << (cnt % 2 == 0 ? "No" : "Yes") << endl;
    return 0;
}