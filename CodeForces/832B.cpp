#include<iostream>
using namespace std;

int main()
{
    string g,s;
    cin >> g >> s;

    int n;
    cin >> n;

    bool good[26] = {false};

    for(int i = 0; i < g.length(); i++)
    {
        good[(int) (g[i] - 97)] = true;
    }


    while(n--)
    {
        string q;
        cin >> q;
        bool isgood = true;
        int j = 0;
        for(int i = 0; i < q.length(); i++)
        {
            if(j >= s.length())
            {
                    isgood = false;
                    cout << "NO";
                    break;
            }
            if(s[j] != q[i])
            {
                if(s[j] == '?' && !good[q[i]-97])
                {
                    isgood = false;
                    cout << "NO";
                    break;
                }
                else if(s[j] == '*' && j != s.length()-1)
                {
                    while(i < q.length() && q[i] != s[j+1] && !good[q[i] - 97])
                        i++;
                    if(q[i] != s[j+1] || i >= q.length())
                    {
                        isgood = false;
                        cout << "NO";
                        break;
                    }
                    j++;
                }
                else if(s[j] == '*' && j == s.length()-1)
                {
                    for(int k = i; k < q.length(); k++)
                    {
                        if(good[q[k]-97])
                        {
                            isgood = false;
                            cout << "NO";
                            break;
                        }
                    }
                    break;
                }
                else if(s[j] != '?' && s[j] != '*')
                {
                    isgood = false;
                    cout << "NO";
                    break;
                }
            }
            j++;
        }
        if(j == s.length() || (j == s.length()-1 && s[s.length()-1] == '*'))
        if(isgood)
            cout << "YES";
            else
                cout << "NO";
        cout << "\n";
    }
}
