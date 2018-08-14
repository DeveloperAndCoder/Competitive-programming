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
#define MAX 1000001
#define N 1000001

using namespace std;

void print(int a[], int n)
{
    forn(i,0,n) cout << a[i] << " ";
    cout << endl;
    return ;
}

bool ispossible(const string &s)
{
    int pos = 0, mi = 0;
    forn(i,0,s.size())
    {
        if(s[i] == '(') pos++;
        else if(pos) pos--;
        else mi++;
    }
    if(mi*pos == 0) return 1;
    return 0;
}

int main()
{
    boost;
    int n;
    cin >> n;
    string s[n];
    forn(i,0,n) cin >> s[i];
    int left[n], right[n];
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    forn(i,0,n)
    {
        int j = 0, br = 0;
        while(j < s[i].size()){
                if(s[i][j] == ')')
                br++;
        else br--;
        j++;
        }

        if(br > 0)
        left[i] = br;
        else if(br < 0) right[i] = -br;
        else left[i] = right[i] = 0;
    }
    //print(left, n);
    //print(right, n);
    ll ans = 0LL;
    forn(i,0,n)
    {
        int p1 = left[i], p2 = right[i];
        int check = 0;
        if(!ispossible(s[i]))
        {
            //cout << i << " = i " << left[i] << " " << right[i] << endl;
            left[i] = INT_MAX;
            right[i] = INT_MAX;
            continue;
        }
        if(left[i] == 0 && right[i] == 0) ans++;
    }
    //print(left, n);
    //print(right, n);
    sort(left, left+n);
    sort(right, right+n);
    ll prev = ans;
    ans = ans*(ans-1);
    ans += prev;
    //cout << ans << " " << prev << endl;
    forn(i,0,n)
    {
        if(left[i] == INT_MAX) break;
        if(left[i] == 0) continue;
        auto rg = equal_range(right, right+n, left[i]);
        //cout << left[i] << *rg.second << " " << *rg.first << endl;
        ans += rg.second-rg.first;
    }
    cout << ans;
    return 0;
}
