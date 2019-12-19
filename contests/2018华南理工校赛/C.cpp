#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string months[13] = {"", "Jan.", "Feb.", "Mar.", "Apr.", "May", "Jun.",
                     "Jul.", "Aug.", "Sept.", "Oct.", "Nov.", "Dec."};

struct Paper
{
    string title, jtitle, jtitleabb;
    int year, month, day;
    string vol, iss, pages, doi;
    int autcnt;
    string first[25], last[25];
} p[50];

string FirstName(string str)
{
    string ret;
    if (str[0] != ' ')
    {
        ret = ret + (char)toupper(str[0]) + ". ";
    }
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i - 1] == ' ')
        {
            ret = ret + (char)toupper(str[i]) + ". ";
        }
    }
    //  cout << string(ret, 0, ret.length() - 1) << endl;
    return string(ret, 0, ret.length() - 1);
}

void IEEE(int i, int pnum)
{
    cout << "[" << i << "] ";
    if (p[pnum].autcnt == 1)
    {
        cout << FirstName(p[pnum].first[0]) << " " << p[pnum].last[0] << ", ";
    }
    else if (p[pnum].autcnt == 2)
    {
        cout << FirstName(p[pnum].first[0]) << " " << p[pnum].last[0] << " and ";
        cout << FirstName(p[pnum].first[1]) << " " << p[pnum].last[1] << ", ";
    }
    else if (p[pnum].autcnt >= 3 && p[pnum].autcnt <= 6)
    {
        for (int i = 0; i < p[pnum].autcnt; i++)
        {
            cout << FirstName(p[pnum].first[i]) << " " << p[pnum].last[i];
            if (i == p[pnum].autcnt - 2)
            {
                cout << ", and ";
            }
            else
            {
                cout << ", ";
            }
        }
    }
    else
    {
        cout << FirstName(p[pnum].first[0]) << " " << p[pnum].last[0] << " et al., ";
    }
    cout << "\"" << p[pnum].title << ",\" ";
    cout << p[pnum].jtitleabb << ", ";
    cout << "vol. " << p[pnum].vol << ", ";
    cout << "no. " << p[pnum].iss << ", ";
    cout << "pp. " << p[pnum].pages << ", ";
    if (p[pnum].month != -1)
    {
        cout << months[p[pnum].month] << " ";
    }
    cout << p[pnum].year;
    cout << ".";
}

void Nature(int i, int pnum)
{
    cout << i << ". ";
    if (p[pnum].autcnt == 1)
    {
        cout << p[pnum].last[0] << ", " << FirstName(p[pnum].first[0]) << " ";
    }
    else if (p[pnum].autcnt == 2)
    {
        cout << p[pnum].last[0] << ", " << FirstName(p[pnum].first[0]) << " & ";
        cout << p[pnum].last[1] << ", " << FirstName(p[pnum].first[1]) << " ";
    }
    else if (p[pnum].autcnt >= 3 && p[pnum].autcnt <= 5)
    {
        for (int i = 0; i < p[pnum].autcnt; i++)
        {
            cout << p[pnum].last[i] << ", " << FirstName(p[pnum].first[i]);
            if (i == p[pnum].autcnt - 2)
            {
                cout << " & ";
            }
            else if (i < p[pnum].autcnt - 2)
            {
                cout << ", ";
            }
            else if (i == p[pnum].autcnt - 1)
            {
                cout << " ";
            }
        }
    }
    else
    {
        cout << p[pnum].last[0] << ", " << FirstName(p[pnum].first[0]) << " et al. ";
    }
    cout << p[pnum].title << ". ";
    cout << p[pnum].jtitleabb << " ";
    cout << p[pnum].vol << ", ";
    cout << p[pnum].pages << " ";
    cout << "(" << p[pnum].year << ")";
    cout << ".";
}

void APA(int i, int pnum)
{
    if (p[pnum].autcnt == 1)
    {
        cout << p[pnum].last[0] << ", " << FirstName(p[pnum].first[0]) << " ";
    }
    else if (p[pnum].autcnt == 2)
    {
        cout << p[pnum].last[0] << ", " << FirstName(p[pnum].first[0]) << ", & ";
        cout << p[pnum].last[1] << ", " << FirstName(p[pnum].first[1]) << " ";
    }
    else if (p[pnum].autcnt >= 3 && p[pnum].autcnt <= 7)
    {
        for (int i = 0; i < p[pnum].autcnt; i++)
        {
            cout << p[pnum].last[i] << ", " << FirstName(p[pnum].first[i]);
            if (i == p[pnum].autcnt - 2)
            {
                cout << ", & ";
            }
            else if (i < p[pnum].autcnt - 2)
            {
                cout << ", ";
            }
            else if (i == p[pnum].autcnt - 1)
            {
                cout << " ";
            }
        }
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            cout << p[pnum].last[i] << ", " << FirstName(p[pnum].first[i]) << ", ";
        }
        cout << "... " << p[pnum].last[p[pnum].autcnt - 1] << ", " << FirstName(p[pnum].first[p[pnum].autcnt - 1]) << " ";
    }
    cout << "(" << p[pnum].year << "). ";
    cout << p[pnum].title << ". ";
    cout << p[pnum].jtitle << ", ";
    cout << p[pnum].vol;
    cout << "(" << p[pnum].iss << "), ";
    cout << p[pnum].pages << ". ";
    cout << "https://doi.org/" << p[pnum].doi;
}

void Harvard(int i, int pnum)
{
    if (p[pnum].autcnt == 1)
    {
        cout << p[pnum].last[0] << ", " << FirstName(p[pnum].first[0]) << " ";
    }
    else if (p[pnum].autcnt == 2)
    {
        cout << p[pnum].last[0] << ", " << FirstName(p[pnum].first[0]) << " and ";
        cout << p[pnum].last[1] << ", " << FirstName(p[pnum].first[1]) << " ";
    }
    else if (p[pnum].autcnt == 3)
    {
        cout << p[pnum].last[0] << ", " << FirstName(p[pnum].first[0]) << ", ";
        cout << p[pnum].last[1] << ", " << FirstName(p[pnum].first[1]) << " and ";
        cout << p[pnum].last[2] << ", " << FirstName(p[pnum].first[2]) << " ";
    }
    else
    {
        cout << p[pnum].last[0] << ", " << FirstName(p[pnum].first[0]) << " et al. ";
    }
    cout << "(" << p[pnum].year << ") ";
    cout << "'" << p[pnum].title << "', ";
    cout << p[pnum].jtitle << ", ";
    cout << p[pnum].vol;
    cout << "(" << p[pnum].iss << "), ";
    cout << "pp. " << p[pnum].pages << ". ";
    cout << "doi: " << p[pnum].doi;
    cout << ".";
}

int main()
{
    //  freopen("in.txt", "r", stdin);
    string in;
    int idx = 0;
    while (cin >> in)
    {
        if (in == "IMPORT")
        {
            idx++;
            getchar();
            getline(cin, p[idx].title);
            getline(cin, p[idx].jtitle);
            getline(cin, p[idx].jtitleabb);
            cin >> p[idx].year >> p[idx].month >> p[idx].day;
            getchar();
            getline(cin, p[idx].vol);
            getline(cin, p[idx].iss);
            getline(cin, p[idx].pages);
            getline(cin, p[idx].doi);
            cin >> p[idx].autcnt;
            getchar();
            for (int i = 0; i < p[idx].autcnt; i++)
            {
                getline(cin, p[idx].last[i], ',');
                getchar();
                getline(cin, p[idx].first[i]);
            }
            //          Harvard(1,1);
        }
        else if (in == "CITE")
        {
            string format;
            int cnt, arr[10];
            cin >> format;
            cin >> cnt;
            for (int i = 0; i < cnt; i++)
            {
                cin >> arr[i];
            }
            for (int i = 0; i < cnt; i++)
            {
                switch (format[0])
                {
                    case 'I': // IEEE
                    {
                        IEEE(i + 1, arr[i]);
                        break;
                    }
                    case 'N': // Nature
                    {
                        Nature(i + 1, arr[i]);
                        break;
                    }
                    case 'A': // APA
                    {
                        APA(i + 1, arr[i]);
                        break;
                    }
                    case 'H': // Harvard
                    {
                        Harvard(i + 1, arr[i]);
                        break;
                    }
                }
                cout << endl;
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}