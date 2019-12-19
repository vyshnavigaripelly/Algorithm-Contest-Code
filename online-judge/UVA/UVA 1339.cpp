#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string enc, dec;
    while (cin >> enc >> dec)
    {
        int flag = 1, cntEnc[26] = {0}, cntDec[26] = {0};
        if (enc.length() != dec.length())
        {
            flag = 0;
        }
        else
        {
            for (int i = 0; i < enc.length(); i++)
            {
                cntEnc[enc[i] - 'A']++;
                cntDec[dec[i] - 'A']++;
            }
            sort(cntEnc, cntEnc + 26);
            sort(cntDec, cntDec + 26);
            for (int i = 0; i < 26; i++)
            {
                if (cntEnc[i] != cntDec[i])
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
