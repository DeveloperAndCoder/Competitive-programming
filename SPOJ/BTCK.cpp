#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

#define ll long long
#define ul unsigned long long
#define forn(i,a,b) for(ul i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001
#define N 1000001

using namespace std;

ll k;
bool solved = 0;
int ans[10];
int arr[10];
bool vis[10]={false};

void print();

bool solve(int n, ll sum, int movei)
{
    //cout << movei << " " << sum << " ";
    //print();
    //cout << endl;
    if(sum > k) {
          //  print();
        //cout << endl << sum << endl;
            return false;
    }
    if(movei == n)
    {
        return sum<=k;
    }
    forn(i,movei,n)
    {
        //if(ans[i] != -1) continue;
        forn(j,0,10)
        {
            if(vis[j]) continue;
            ans[i]=j;
            vis[j]=1;
            if(solve(n, sum + arr[i]*j, movei+1)) return true;
            vis[j]=0;
        }
        //ans[i] = -1;
    }
    return false;
}

void print()
{
    forn(i,0,10)
    cout << ans[i] << " ";
}


int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        fill(ans, ans+10, -1);
        forn(i,0,10) cout << ans[i] << " ";
        cout << endl;
        forn(i,0,10) cin >> arr[i];
        cin >> k;
        if(solve(10,0LL,0)) print();
        else cout << -1;
        cout<<endl;
    }
}

/*
1
1 2 3 4 5 6 7 8 9 10
200
*/
