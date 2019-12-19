#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int cnt = 0, m50 = n / 50, m25 = n / 25, m10 = n / 10, m5 = n / 5;
        for (int i = 0; i <= m50; i++)
        {
            for (int j = 0; j <= m25; j++)
            {
                for (int k = 0; k <= m10; k++)
                {
                    for (int l = 0; l <= m5; l++)
                    {
                        int n1 = n - i * 50 - j * 25 - k * 10 - l * 5;
                        if (n1 >= 0 && i + j + k + l + n1 <= 100)
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
