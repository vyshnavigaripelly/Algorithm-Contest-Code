#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        string words[1000];
        int left[1000] = {0}, l = 0, right[1000] = {0}, r = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (i == 0 && isalpha(s[i]))
            {
                left[0] = 0;
                l++;
            }
            if (i != 0 && isalpha(s[i]) && !isalpha(s[i - 1]))
            {
                left[l] = i;
                l++;
            }
            if (i != s.length() - 1 && isalpha(s[i]) && !isalpha(s[i + 1]))
            {
                right[r] = i;
                r++;
            }
            if (i == s.length() - 1 && isalpha(s[i]))
            {
                right[r] = i;
                r++;
            }
        }
        for (int i = 0; i < l; i++)
        {
            words[i] = string(s, left[i], right[i] - left[i] + 1);
        }
        if (l != 0)
        {
            for (int i = 0; i < l; i++)
            {
                if (find(words, words + i, words[i]) != words + i)
                {
                    continue;
                }
                else
                {
                    cout << words[i] << endl;
                }
            }
        }
    }
    return 0;
}
