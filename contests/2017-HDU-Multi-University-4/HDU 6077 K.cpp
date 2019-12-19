#include <iostream>
#include <bitset>

using namespace std;

char s[8][25];

int check(int i)
{
    int ans = 0;
    if (s[0][i + 1] == 'X' && s[0][i + 2] == 'X')
    {
        ans |= (1 << 6);
    }
    if (s[1][i] == 'X' && s[2][i] == 'X')
    {
        ans |= (1 << 5);
    }
    if (s[1][i + 3] == 'X' && s[2][i + 3] == 'X')
    {
        ans |= (1 << 4);
    }
    if (s[3][i + 1] == 'X' && s[3][i + 2] == 'X')
    {
        ans |= (1 << 3);
    }
    if (s[4][i] == 'X' && s[5][i] == 'X')
    {
        ans |= (1 << 2);
    }
    if (s[4][i + 3] == 'X' && s[5][i + 3] == 'X')
    {
        ans |= (1 << 1);
    }
    if (s[6][i + 1] == 'X' && s[6][i + 2] == 'X')
    {
        ans |= (1 << 0);
    }
    int arr[10] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010,
                   0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
    for (int i = 0; i < 10; i++)
    {
        if (ans == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i < 7; i++)
        {
            scanf("%s", s[i]);
        }
        printf("%d%d:%d%d\n", check(0), check(5), check(12), check(17));
    }
    return 0;
}