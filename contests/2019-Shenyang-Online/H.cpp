#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int royal[5] = {1, 10, 11, 12, 13};

struct Person
{
    string name;
    int cards[5], cnt[15];
    long long rank;
} arr[100007];

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            memset(arr[i].cnt, 0, sizeof(arr[i].cnt));
            memset(arr[i].cards, 0, sizeof(arr[i].cards));
            cin >> arr[i].name;
            string str;
            cin >> str;
            for (int j = 0, cur = 0; j < str.length(); j++)
            {
                if (str[j] == 'A')
                    arr[i].cards[cur] = 1;
                else if (str[j] == 'J')
                    arr[i].cards[cur] = 11;
                else if (str[j] == 'Q')
                    arr[i].cards[cur] = 12;
                else if (str[j] == 'K')
                    arr[i].cards[cur] = 13;
                else if (str[j] == '1')
                {
                    arr[i].cards[cur] = 10;
                    j++;
                }
                else
                {
                    arr[i].cards[cur] = str[j] - '0';
                }
                cur++;
            }
            for (int j = 0; j < 5; j++)
            {
                arr[i].cnt[arr[i].cards[j]]++;
            }
            sort(arr[i].cards, arr[i].cards + 5);
        }
        for (int i = 0; i < n; i++)
        {
            int *cards = arr[i].cards, sum = accumulate(cards, cards + 5, 0);
            // Royal Straight
            if (equal(cards, cards + 5, royal))
            {
                arr[i].rank = 7 * 1e6;
                continue;
            }
            // Straight
            int straight = 1;
            for (int j = 1; j < 5; j++)
            {
                if (cards[j] - cards[j - 1] != 1)
                {
                    straight = 0;
                }
            }
            if (straight)
            {
                arr[i].rank = 6 * 1e6 + cards[4] * 1e4;
                continue;
            }
            // Four of a kind
            int *four = find(arr[i].cnt, arr[i].cnt + 15, 4);
            if (four != arr[i].cnt + 15)
            {
                arr[i].rank = 5 * 1e6 + (four - arr[i].cnt) * 1e4 + (sum - (four - arr[i].cnt) * 4) * 1e2;
                continue;
            }
            int *three = find(arr[i].cnt, arr[i].cnt + 15, 3),
                *firsttwo = find(arr[i].cnt, arr[i].cnt + 15, 2),
                *lasttwo = find(firsttwo + 1, arr[i].cnt + 15, 2);
            if (three != arr[i].cnt + 15)
            {
                // Full House
                if (firsttwo != arr[i].cnt + 15)
                {
                    arr[i].rank = 4 * 1e6 + (three - arr[i].cnt) * 1e4 + (firsttwo - arr[i].cnt) * 1e2;
                    continue;
                }
                // Three of a Kind
                arr[i].rank = 3 * 1e6 + (three - arr[i].cnt) * 1e4 + (sum - (three - arr[i].cnt) * 3) * 1e2;
                continue;
            }
            if (firsttwo != arr[i].cnt + 15)
            {
                if (lasttwo != arr[i].cnt + 15)
                {
                    // Two Pairs
                    arr[i].rank = 2 * 1e6 + (lasttwo - arr[i].cnt) * 1e4 + (firsttwo - arr[i].cnt) * 1e2 + (sum - (lasttwo - arr[i].cnt) * 2 - (firsttwo - arr[i].cnt) * 2);
                    continue;
                }
                // Pair
                arr[i].rank = 1 * 1e6 + (firsttwo - arr[i].cnt) * 1e4 + (sum - (firsttwo - arr[i].cnt) * 2) * 1e2;
                continue;
            }
            arr[i].rank = sum;
        }
        sort(arr, arr + n, [](const Person &a, const Person &b) {
            return a.rank > b.rank || (a.rank == b.rank && a.name < b.name);
        });
        for (int i = 0; i < n; i++)
        {
            cout << arr[i].name << endl;
        }
    }
    return 0;
}