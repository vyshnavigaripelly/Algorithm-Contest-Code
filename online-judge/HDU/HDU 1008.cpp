#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        int floor = 0, time = 0;
        while (n--)
        {
            int next;
            cin >> next;
            if (floor < next)
            {
                time += (next - floor) * 6 + 5;
            }
            else
            {
                time += (floor - next) * 4 + 5;
            }
            floor = next;
        }
        cout << time << endl;
    }
    return 0;
}
