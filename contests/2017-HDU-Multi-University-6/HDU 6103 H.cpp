#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // 考虑枚举中间点，A和B关于中间点对称，记A的左端点为L，B的右端点为R，R-L+1奇偶分开讨论，尺取法计算区间
        string str;
        int m, len, ans = 0;
        cin >> m >> str;
        len = str.length();
        for (int mid = 0; mid < len; mid++)
        {
            // 奇数
            int sublen = 0, num[5007];
            while (++sublen)
            {
                if (mid + sublen >= len || mid - sublen < 0)
                {
                    sublen--;
                    break;
                }
                num[sublen - 1] = abs(str[mid + sublen] - str[mid - sublen]);
            }
            int st = 0, en = 0, sum = 0;
            while (1)
            {
                while (sum + num[en] <= m && en < sublen)
                {
                    sum += num[en];
                    ans = max(ans, en - st + 1);
                    en++;
                }
                sum -= num[st++];
                if (st >= sublen)
                    break;
            }
            // 偶数
            sublen = 0, st = 0, en = 0, sum = 0;
            while (++sublen)
            {
                if (mid - (sublen - 1) < 0 || (mid + 1 + (sublen - 1)) >= len)
                {
                    sublen--;
                    break;
                }
                num[sublen - 1] = abs(str[mid - (sublen - 1)] - str[mid + sublen]);
            }
            while (1)
            {
                while (sum + num[en] <= m && en < sublen)
                {
                    sum += num[en];
                    ans = max(ans, en - st + 1);
                    en++;
                }
                sum -= num[st++];
                if (st >= sublen)
                    break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}