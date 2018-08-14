#include<iostream>
#include<vector>
#include<cstring>
#include<stack>

#define forn(i,a,n) for(int i = 0; i < n; i++)
#define ll long long
#define eb emplace_back
#define mem(array,value) memset(array, value, sizeof(array))

using namespace std;

char a[51][51];
bool vis[51][51];
int n,m;
vector<int> row, col;
bool ans = 1;

bool check(int i, int j)
{
    if(i >= 0 && i < n && j >= 0 && j < m)
        return 1;
    return 0;
}

int search(const vector<int> &v, int x)
{
    forn(i,0,v.size())
        if(v[i] == x)
            return x;
    return -1;
}
void process2(int x, int y, vector<int> &row, vector<int> &col);
void process1(int x, int y, vector<int> &row, vector<int> &col)
{
    //cout << "p1 " << x << " " << y << endl;
    vis[x][y] =1;
    if(ans == 0) return;
    forn(j,0,m)
    {
        int i = x;
        if(j == y) continue;
        if(a[i][j] == '#')
        {
            if(search(col,j)==-1)
            {
                //cout << " i = " << i << " j = " << j << endl;
                col.eb(j);
                process2(i,j,row,col);
            }
            //cout << i << " " << j << " " << search(col,j) << " " << a[i][search(col,j)] << endl;
        }
        else
        {
            if(search(col,j) == -1);
            else
            {
                ans = 0;
                return;
            }
        }
    }
}
    /*
    if(tr) goto las;
    fc:;
    */
void process2(int x, int y, vector<int> &row, vector<int> &col)
{
    //cout << "p2 " << x << " " << y << endl;
    vis[x][y] =1;
    forn(i,0,n)
    {
        int j = y;
        if(i == x) continue;
        if(a[i][j] == '#')
        {
            if(search(row, i) == -1)
            {
                row.eb(i);
                process1(i,j,row,col);
            }
        }
        else
        {
            if(search(row,i) == -1);
            else
            {
                ans = 0;
                return;
            }
        }
    }
    /*if(tr) goto ff;
    las:;*/
    return;
}

int main()
{
    //cin >> n >> m;
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    n=m=50;
    forn(i,0,n)
    forn(j,0,m) a[i][j] = '#';//cin >> a[i][j];
    forn(i,0,n)forn(j,0,m) vis[i][j] = 0;
    forn(i,0,n)
    {
        if(ans == 0) break;
        forn(j,0,m)
        {
            if(vis[i][j]) continue;
            if(ans == 0) break;
            if(a[i][j] == '#')
            {
                vector<int> row;
                vector<int> col;
                row.eb(i);col.eb(j);
                process2(i,j,row,col);
            }
        }
    }
    if(ans) cout << "Yes";
    else cout << "No";
    return 0;
}
