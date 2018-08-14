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
#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001
#define N 400001
#define mod 1000000007

using namespace std;

int pk = 0, lala = 0;
bool vis[9];

void print(int p[], int n)
{
    for(int i = 0; i < n; i++) cout << p[i] << " ";
    cout << endl;
}

bool check(int perm[], int n, int k)
{
    int ck = 0;
    forn(i,0,n)
    {
        if(perm[i] == 0) return false;
        if(i>0 && perm[i] > perm[i-1]) ck++;
    }
   // print(perm,n);
    return ck == k;
}

void solve(int perm[], int n, int k, int index)
{
    //print(perm,n);
    //cout << index << endl << endl;
    if(index == lala+1)
    {
        if(check(perm, n, k))
        {
            pk++;
        }
        return;
    }
    forn(i,index,n)
    {
        if(perm[i] == 0)
        {
            forn(j,1,n+1)
            {
                if(vis[j]) continue;
                vis[j] = 1;
                perm[i] = j;
                solve(perm, n, k, i+1);
                perm[i] = 0;
                vis[j] = 0;
            }
        }
    }
    return;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        lala= -1;
        pk = 0;
        forn(i,0,9) vis[i] = false;
        int n, k;
        cin >> n >> k;
        int perm[n];
        forn(i,0,n) {
            cin >> perm[i];
            if(perm[i])
            vis[perm[i]] = true;
            else lala = i;
        }
        solve(perm, n, k, 0);
        cout << pk << endl;
    }
}
