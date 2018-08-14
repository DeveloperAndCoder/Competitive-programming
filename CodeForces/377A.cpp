#include<iostream>
#include<algorithm>
#include<stack>
#include<utility>

#define forn(i,a,b) for(int i =a;i < b; i++)

using namespace std;

char maze[501][501];//, ans[501][501];

bool check(int pos1, int pos2, int n, int m)
{
    if(pos1 < 0 || pos2 < 0 || pos1 >= n || pos2 >= m) return false;
    return (maze[pos1][pos2] == 'X');
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int posx , posy, nm = 0;
    forn(i,0,n)
    {
        forn(j,0,m)
        {
            cin >> maze[i][j];
            if(maze[i][j] == '.')
            {
                nm++;
                maze[i][j] = 'X';
                posx = i;
                posy = j;
            }
          //  ans[i][j] = maze[i][j];
        }
    }
    int pos1, pos2;
    stack< pair<int,int> > trg;
    trg.push(make_pair(posx, posy));
    forn(i,0,nm-k)
    {
        if(trg.empty()) {cout << "EMPTY!\n";break;}
        pair<int, int> p = trg.top();
        trg.pop();
        pos1 = p.first;
        pos2 = p.second;
        if(check(pos1-1, pos2, n, m))
        {
            trg.push(make_pair(pos1-1,pos2));
        }
        if(check(pos1+1, pos2, n, m))
        {
            trg.push(make_pair(pos1+1,pos2));
        }
        if(check(pos1, pos2-1, n, m))
        {
            trg.push(make_pair(pos1,pos2-1));
        }
        if(check(pos1, pos2+1, n, m))
        {
            trg.push(make_pair(pos1,pos2+1));
        }
        //ans[pos1][pos2] = '.';
        maze[pos1][pos2] = '.';
    }
    forn(i,0,n)
    {
        forn(j,0,m)
        {
            cout << maze[i][j];
        }
        cout << '\n';
    }
    return 0;
}
