#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, s1, s2, s3;
        int tmp1 = 0, tmp2 = 0, tmp3 = 0;
        int arr[3], brr[3], crr[3];
        cin >> s;
        for (int i = 0; i < 9; i++)
        {
            if (s[i] == 'g')
            {
                arr[tmp1] = i;
                tmp1++;
                s2 += "g";
                s3 += "g";
            }
            if (s[i] == 'a')
            {
                brr[tmp2] = i;
                tmp2++;
                s1 += "a";
                s3 += "a";
            }
            if (s[i] == 'o')
            {
                crr[tmp3] = i;
                tmp3++;
                s2 += "o";
                s1 += "o";
            }
        }
        int ans = -1;
        int flag = 1, sum = 0, temp = 0;
        for (int i = 0; i < 2; i++)
        {
            if (arr[i + 1] - arr[i] != 1)
                flag = 0;
        }
        for (int i = 0; i < 4; i++)
        {
            if (s1[i] == s1[i + 1] && s1[i + 1] == s1[i + 2])
            {
                sum += 2;
                temp = 1;
                break;
            }
        }
        if (flag)
            sum++;
        if (!temp)
            sum++;
        ans = max(ans, sum);
        flag = 1, sum = 0, temp = 0;
        for (int i = 0; i < 2; i++)
        {
            if (brr[i + 1] - brr[i] != 1)
                flag = 0;
        }
        for (int i = 0; i < 4; i++)
        {
            if (s2[i] == s2[i + 1] && s2[i + 1] == s2[i + 2])
            {
                sum += 2;
                temp = 1;
                break;
            }
        }
        if (flag)
            sum++;
        if (!temp)
            sum++;
        ans = max(ans, sum);
        flag = 1, sum = 0, temp = 0;
        for (int i = 0; i < 2; i++)
        {
            if (crr[i + 1] - crr[i] != 1)
                flag = 0;
        }
        for (int i = 0; i < 4; i++)
        {
            if (s3[i] == s3[i + 1] && s3[i + 1] == s3[i + 2])
            {
                sum += 2;
                temp = 1;
                break;
            }
        }
        if (flag)
            sum++;
        if (!temp)
            sum++;
        ans = max(ans, sum);
        cout << ans << endl;
    }
    return 0;
}