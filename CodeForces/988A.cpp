#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<stack>
#include<climits>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define MAX 10001

#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

bool ff(vector<int> ans, int a[], int n)
{
    for(int i = 0; i < ans.size(); i++)
    {
        if(a[ans[i]] == n) return false;
    }
    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    forn(i,0,n) cin >> a[i];
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        if(ans.size() == 0)
        {
            ans.push_back(i);
        }
        else if(ff(ans, a, a[i]))
        {
            ans.push_back(i);
        }
    }
    if(ans.size() >= k)
    {
        cout << "YES\n";
        forn(i,0,k) cout << ans[i]+1 << " ";
    }
    else cout << "NO";
    return 0;
}
