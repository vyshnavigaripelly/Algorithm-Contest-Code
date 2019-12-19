#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;

int Next[N], sLen, pLen;
char ans[3][2][20] = {"my child!", "oh, child!", "jntm!", "friend!", "my teacher!", "senior!"};

void GetNextval(char *str2)
{
    int pLen = strlen(str2);
    Next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)
    {
        if (k == -1 || str2[j] == str2[k])
        {
            ++j;
            ++k;
            if (str2[j] != str2[k])
                Next[j] = k;
            else
                Next[j] = Next[k];
        }
        else
        {
            k = Next[k];
        }
    }
}

int KmpSearch(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    while (i < sLen)
    {
        while (i < sLen && j < pLen)
        {
            if (j == -1 || str1[i] == str2[j])
            {
                i++;
                j++;
            }
            else
            {
                j = Next[j];
            }
            if (j == pLen)
            {
                j = 0;
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    char str1[N], str2[N];
    scanf("%s", str1);
    sLen = strlen(str1);
    int q;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%s", str2);
        pLen = strlen(str2);
        if (sLen > pLen)
        {
            GetNextval(str2);
            int flag = KmpSearch(str1, str2);
            puts(ans[0][flag]);
        }
        else if (sLen == pLen)
        {
            GetNextval(str2);
            int flag = KmpSearch(str1, str2);
            puts(ans[1][flag]);
        }
        else
        {
            swap(str1, str2);
            swap(sLen, pLen);
            GetNextval(str2);
            int flag = KmpSearch(str1, str2);
            puts(ans[2][flag]);
            swap(str1, str2);
            swap(sLen, pLen);
        }
    }
    return 0;
}
