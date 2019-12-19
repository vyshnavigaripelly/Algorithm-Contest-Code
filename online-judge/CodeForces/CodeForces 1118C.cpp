#include <iostream>
#include <vector>

using namespace std;

int arr[5007], cnt[1007], mat[25][25];

vector<pair<int, int>> vec;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n * n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    for (int i = 1; i <= 1000; i++)
    {
        if (cnt[i])
        {
            vec.push_back({cnt[i], i});
        }
    }
    for (int cur : {4, 2, 1})
    {
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            for (int j = 0; j < (n + 1) / 2; j++)
            {
                int tmp;
                if (i != n - i - 1 && j != n - j - 1)
                {
                    tmp = 4;
                }
                else if ((i != n - i - 1) + (j != n - j - 1) == 1)
                {
                    tmp = 2;
                }
                else
                {
                    tmp = 1;
                }
                if (cur == tmp)
                {
                    for (int k = 0; k < vec.size(); k++)
                    {
                        if (vec[k].first >= cur)
                        {
                            vec[k].first -= cur;
                            mat[i][j] = mat[n - i - 1][j] = mat[i][n - j - 1] = mat[n - i - 1][n - j - 1] = vec[k].second;
                            break;
                        }
                        if (k == vec.size() - 1)
                        {
                            cout << "NO" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " \n"[j == n - 1];
        }
    }
    return 0;
}