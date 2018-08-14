#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define N 102
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

int stones[102][102];
int grid[101][101];

bool isbound(int x, int y, int h, int w)
{
    return (x >= 0 && x < h && y >= 0 && y < w);
}

int collect(int x, int y, int h, int w)
{
    if(x == h-1 && isbound(x,y,h,w)) {
            stones[x][y] = grid[x][y];
            return stones[x][y];
    }
    if(x >= h || y >= w || x < 0 || y < 0) {
            stones[x][y] = 0;
            return 0;
    }
    int res = 0;
    if(stones[x+1][y] == -1) stones[x+1][y] = collect(x+1,y,h,w);
    if(stones[x+1][y+1] == -1) stones[x+1][y+1] = collect(x+1,y+1,h,w);
    if(isbound(x+1,y-1,h,w))
    {
        if(stones[x+1][y-1] == -1) stones[x+1][y-1] = collect(x+1,y-1,h,w);
        res = max(stones[x+1][y-1], max(stones[x+1][y], stones[x+1][y+1])) + grid[x][y];
    }
    else
        res = max(stones[x+1][y], stones[x+1][y+1]) + grid[x][y];
    stones[x][y] = res;
    return stones[x][y];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        forn(i,0,101)
        forn(j,0,101)
        stones[i][j] = -1;
        int h, w;
        cin >> h >> w;
        forn(i,0,h)
        forn(j,0,w) cin >> grid[i][j];
        int ans = 0;
        for(int i = 0; i < w; i++)
        {
            ans = max(ans, collect(0,i,h,w));
           // cout << i << " " << ans << endl;
        }
        cout << ans << endl;
    }
}
