#include<iostream>
#include<vector>
#include<string>

#define forn(i,a,b) for(int i = a;i < b; i++)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    vector<char> v[r];
    char ch;
    int s_x=0, s_y=0;
    int e_x=0, e_y = 0;
    forn(i,0,r)
    {
        forn(j,0,c)
        {
            cin >> ch;
            //cout << i << " " << j << " " << ch << endl;
            v[i].push_back(ch);
            if(ch == 'S')
            {
                s_x = i;
                s_y = j;
            }
            if(ch == 'E')
            {
                e_x = i;
                e_y = j;
            }
        }
    }
    string path;
    cin >> path;
    int len = path.length();
    bool inc = true;
    int ans = 0;
    forn(u,0,4)
    {
        forn(d,0,4)
        {
            if(d == u)
                continue;
            forn(l,0,4)
            {
                if(l == u || l == d)
                continue;
                forn(ri,0,4)
                {

                    inc = true;
                    if(ri == u || ri == d || ri == l)
                    continue;
                    //cout << ri << " " << l << " " << d << " " << u << endl;
                    int p_x = s_x;
                    int p_y = s_y;


                    forn(i,0,len)
                    {
                        ch = path[i];
                        if(ch-'0' == ri)
                        {
                            p_x++;
                        }
                        if(ch-'0' == l)
                        {
                            p_x--;
                        }
                        if(ch-'0' == d)
                        {
                            p_y++;
                        }
                        if(ch-'0' == u)
                        {
                            p_y--;
                        }
                        if(p_x < 0 || p_y < 0 || p_x >= r || p_y >= c || v[p_x][p_y] == '#')
                        {

                            inc = false;
                            break;
                        }
                        if(v[p_x][p_y] == 'E')
                        {
                            break;
                        }
                    }
                   // cout << ri << " " << l << " " << d << " " << u << " " << inc << " " << p_x << " " << p_y << endl;
                    if(inc && v[p_x][p_y] == 'E')
                    {
                        ans++;
                    }

                }
            }
        }
    }
    cout << ans;
    return 0;
}
