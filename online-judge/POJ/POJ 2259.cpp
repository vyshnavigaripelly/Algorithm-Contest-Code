#include <iostream>
#include <queue>
#include <string>

using namespace std;

int flag[1000007];

int main()
{
    int t;
    for (int cas = 1; cin >> t && t; cas++)
    {
        queue<int> q, team[1007];
        for (int i = 1; i <= t; i++)
        {
            int n;
            cin >> n;
            while (n--)
            {
                int x;
                cin >> x;
                flag[x] = i;
            }
        }
        cout << "Scenario #" << cas << endl;
        string s;
        while (cin >> s && s != "STOP")
        {
            if (s == "ENQUEUE")
            {
                int x;
                cin >> x;
                int nowteam = flag[x];
                if (team[nowteam].empty())
                {
                    q.push(nowteam);
                    team[nowteam].push(x);
                }
                else
                {
                    team[nowteam].push(x);
                }
            }
            else if (s == "DEQUEUE")
            {
                int nowteam = q.front();
                cout << team[nowteam].front() << endl;
                team[nowteam].pop();
                if (team[nowteam].empty())
                {
                    q.pop();
                }
            }
        }
        cout << endl;
    }
    return 0;
}