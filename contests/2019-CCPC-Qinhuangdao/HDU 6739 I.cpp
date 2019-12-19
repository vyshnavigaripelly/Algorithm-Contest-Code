#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int mp[26][6][26][6];
char key[26][5];
char str[100007];
int ans[100007][6];

int main()
{
    strcpy(key['Y' - 'A'], "QQQ");
    strcpy(key['V' - 'A'], "QQW");
    strcpy(key['G' - 'A'], "EQQ");
    strcpy(key['C' - 'A'], "WWW");
    strcpy(key['X' - 'A'], "QWW");
    strcpy(key['Z' - 'A'], "EWW");
    strcpy(key['T' - 'A'], "EEE");
    strcpy(key['F' - 'A'], "EEQ");
    strcpy(key['D' - 'A'], "EEW");
    strcpy(key['B' - 'A'], "EQW");
    for (int i = 0; i < 26; i++)
    {
        if (key[i][0] == '\0')
            continue;
        for (int j = 0; j < 26; j++)
        {
            if (key[j][0] == '\0')
                continue;
            int ordA[3] = {0, 1, 2}, cntA = 0;
            do
            {
                int ordB[3] = {0, 1, 2}, cntB = 0;
                do
                {
                    int ans;
                    if (key[i][ordA[0]] == key[j][ordB[0]] && key[i][ordA[1]] == key[j][ordB[1]] && key[i][ordA[2]] == key[j][ordB[2]])
                        ans = 0;
                    else if (key[i][ordA[1]] == key[j][ordB[0]] && key[i][ordA[2]] == key[j][ordB[1]])
                        ans = 1;
                    else if (key[i][ordA[2]] == key[j][ordB[0]])
                        ans = 2;
                    else
                        ans = 3;
                    mp[i][cntA][j][cntB] = ans;
                    cntB++;
                } while (next_permutation(ordB, ordB + 3));
                cntA++;
            } while (next_permutation(ordA, ordA + 3));
        }
    }
    while (~scanf("%s", str))
    {

        int len = strlen(str);
        for (int i = 0; i < 6; i++)
        {
            ans[0][i] = 3;
        }
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                ans[i][j] = 1 << 30;
                for (int k = 0; k < 6; k++)
                {
                    ans[i][j] = min(ans[i][j], ans[i - 1][k] + mp[str[i - 1] - 'A'][k][str[i] - 'A'][j]);
                }
            }
        }
        int sum = *min_element(ans[len - 1], ans[len - 1] + 6) + len;
        printf("%d\n", sum);
    }
    return 0;
}