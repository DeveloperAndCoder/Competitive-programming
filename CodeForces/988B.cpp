#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<climits>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define MAX 10001
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

bool cmp(string &s1, string &s2)
{
    return s1.size()<s2.size();
}

bool issub(string &s1, string &s2)
{
    for(int i = 0; s2.size()-i+1 >= s1.size(); i++)
    {
        bool is = 1;
        for(int j = 0; j < s1.size(); j++)
            if(s1[j] != s2[i+j])
            {
                is = 0;break;
            }
        if(is) return true;
    }
    return false;
}
int main()
{
    boost;
    int n;
    cin >> n;
    vector<string> v(n);
    forn(i,0,n) cin >> v[i];
    sort(v.begin(),v.end(),cmp);
    //forn(i,0,n) cout << v[i] << " ";
    cout << endl;
    forn(i,0,n-1)
    {
        if(!issub(v[i],v[i+1]))
        {
           // cout << v[i] << " " << v[i+1] << endl;
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    forn(i,0,n) cout << v[i] << "\n";
    return 0;
}
