#include <iostream>
#include <string>

using namespace std;

string str1, str2, ans;

int main()
{
    int t, l1, l2, r1, r2;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        ans.clear();
        cin >> str1 >> str2;
        l1 = 0, l2 = 0, r1 = str1.size() - 1, r2 = str2.size() - 1;
        while (ans.size() < str1.size() + str2.size())
        {
            int tmpu = -1, tmpd = -1;
            char dir1, dir2, upordown = 'u';
            if (l1 <= r1)
            {
                if (str1[l1] == str1[r1])
                {
                    int tmpl1 = l1, tmpr1 = r1;
                    while (tmpl1 <= tmpr1 && str1[tmpl1] == str1[tmpr1])
                    {
                        tmpl1++;
                        tmpr1--;
                    }
                    if (tmpl1 > tmpr1)
                    {
                        dir1 = 'l';
                        tmpu = str1[l1];
                    }
                    else if (str1[tmpl1] > str1[tmpr1])
                    {
                        dir1 = 'l';
                        tmpu = str1[l1];
                    }
                    else
                    {
                        dir1 = 'r';
                        tmpu = str1[r1];
                    }
                }
                else
                {
                    if (str1[l1] > str1[r1])
                    {
                        dir1 = 'l';
                        tmpu = str1[l1];
                    }
                    else
                    {
                        dir1 = 'r';
                        tmpu = str1[r1];
                    }
                }
            }
            if (l2 <= r2)
            {
                if (str2[l2] == str2[r2])
                {
                    int tmpl2 = l2, tmpr2 = r2;
                    while (tmpl2 <= tmpr2 && str2[tmpl2] == str2[tmpr2])
                    {
                        tmpl2++;
                        tmpr2--;
                    }
                    if (tmpl2 > tmpr2)
                    {
                        dir2 = 'l';
                        tmpd = str2[l2];
                    }
                    else if (str2[tmpl2] > str2[tmpr2])
                    {
                        dir2 = 'l';
                        tmpd = str2[l2];
                    }
                    else
                    {
                        dir2 = 'r';
                        tmpd = str2[r2];
                    }
                }
                else
                {
                    if (str2[l2] > str2[r2])
                    {
                        dir2 = 'l';
                        tmpd = str2[l2];
                    }
                    else
                    {
                        dir2 = 'r';
                        tmpd = str2[r2];
                    }
                }
            }
            if (tmpu == tmpd)
            {
                if (dir1 == 'l' && dir2 == 'l')
                {
                    int tmpl1 = l1, tmpl2 = l2;
                    while ((tmpl1 <= r1 || tmpl2 <= r2) && str1[tmpl1] == str2[tmpl2])
                    {
                        tmpl1++;
                        tmpl2++;
                        if (tmpl1 <= r1 || tmpl2 <= r2)
                        {
                            if (tmpl1 > r1)
                                tmpl1--;
                            if (tmpl2 > r2)
                                tmpl2--;
                        }
                    }
                    if (tmpl1 > r1 || tmpl2 > r2)
                    {
                        upordown = 'u';
                    }
                    else if (str1[tmpl1] > str2[tmpl2])
                    {
                        upordown = 'u';
                    }
                    else
                    {
                        upordown = 'd';
                    }
                }
                if (dir1 == 'l' && dir2 == 'r')
                {
                    int tmpl1 = l1, tmpr2 = r2;
                    while ((tmpl1 <= r1 || tmpr2 >= l2) && str1[tmpl1] == str2[tmpr2])
                    {
                        tmpl1++;
                        tmpr2--;
                        if (tmpl1 <= r1 || tmpr2 >= l2)
                        {
                            if (tmpl1 > r1)
                                tmpl1--;
                            if (tmpr2 < l2)
                                tmpr2++;
                        }
                    }
                    if (tmpl1 > r1 && tmpr2 < l2)
                    {
                        upordown = 'u';
                    }
                    else if (str1[tmpl1] > str2[tmpr2])
                    {
                        upordown = 'u';
                    }
                    else
                    {
                        upordown = 'd';
                    }
                }
                if (dir1 == 'r' && dir2 == 'r')
                {
                    int tmpr1 = r1, tmpr2 = r2;
                    while ((tmpr1 >= l1 || tmpr2 >= l2) && str1[tmpr1] == str2[tmpr2])
                    {
                        tmpr1--;
                        tmpr2--;
                        if (tmpr1 >= l1 || tmpr2 >= l2)
                        {
                            if (tmpr1 < l1)
                                tmpr1++;
                            if (tmpr2 < l2)
                                tmpr2++;
                        }
                    }
                    if (tmpr1 < l1 || tmpr2 < l2)
                    {
                        upordown = 'u';
                    }
                    else if (str1[tmpr1] > str2[tmpr2])
                    {
                        upordown = 'u';
                    }
                    else
                    {
                        upordown = 'd';
                    }
                }
                if (dir1 == 'r' && dir2 == 'l')
                {
                    int tmpr1 = r1, tmpl2 = l2;
                    while ((tmpr1 >= l1 || tmpl2 <= r2) && str1[tmpr1] == str2[tmpl2])
                    {
                        tmpr1--;
                        tmpl2++;
                        if (tmpr1 >= l1 || tmpl2 <= r2)
                        {
                            if (tmpr1 < l1)
                                tmpr1++;
                            if (tmpl2 > r2)
                                tmpl2--;
                        }
                    }
                    if (tmpr1 < l1 || tmpl2 > r2)
                    {
                        upordown = 'u';
                    }
                    else if (str1[tmpr1] > str2[tmpl2])
                    {
                        upordown = 'u';
                    }
                    else
                    {
                        upordown = 'd';
                    }
                }
            }
            else
            {
                if (tmpu < tmpd)
                    upordown = 'd';
            }
            if (upordown == 'u')
            {
                if (dir1 == 'l')
                {
                    ans.push_back(str1[l1]);
                    l1++;
                }
                else
                {
                    ans.push_back(str1[r1]);
                    r1--;
                }
            }
            else
            {
                if (dir2 == 'l')
                {
                    ans.push_back(str2[l2]);
                    l2++;
                }
                else
                {
                    ans.push_back(str2[r2]);
                    r2--;
                }
            }
        }
        cout << "Case #" << cas << ": " << ans << endl;
    }
    return 0;
}
