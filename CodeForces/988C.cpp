#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<climits>
#include<set>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define MAX 3000000007
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    boost;
    int k;
    cin >> k;
    vector<vector<ll> > v,ind;
    vector<ll> tt;
    vector<set<ll> > total;
    forn(i,0,k)
    {
        int n;
        cin >> n;
        vector<ll> v1(n);
        forn(i,0,n) cin >> v1[i];
        v.emplace_back(v1);
    }
    forn(i,0,k)
    {
        ll sum = 0;
        forn(j,0,v[i].size())   sum += v[i][j];
        vector<ll> vv(v[i].size(),-MAX);
        set<ll> st;
        forn(j,0,v[i].size()){
            st.insert(sum-v[i][j]);
            vv[j] = sum-v[i][j];
        }
        total.emplace_back(st);
        /*
        cout << "i = " << i << endl;
        for(set<ll>::iterator it = st.begin(); it != st.end(); it++)
            cout << *it << " ";
        cout << endl;
        */
        ind.emplace_back(vv);
    }
    /*
    forn(i,0,k)
    {
        for(int k1 = 0; k1 < ind[i].size(); k1++)
        {
            cout << ind[i][k1] << " ";
        }
        cout << endl;
    }
    */
    ll sum = 0;
    bool yes = false;
    /*
    forn(i,0,total.size()) cout << total[i] << " ";
    cout << endl;
    */
    //exit(0);
    for(vector<set<ll> >::iterator itt = total.begin(); itt != total.end(); itt++)
    for(set<ll>::iterator it = itt->begin(); it != itt->end(); it++)
    {
        //cout << *it << " ";
        tt.emplace_back(*it);
    }
    /*
    forn(i,0,tt.size()) cout << tt[i] << " ";
        cout << endl;*/
    sort(tt.begin(), tt.end());
    forn(i,0,tt.size()-1)
    {
        if(tt[i] == tt[i+1])
        {
            yes = true;
            sum = tt[i];
        }
    }
    if(yes)
    {
        cout << "YES\n";
        int pri = 0;
        forn(i,0,k)
        {
            if(pri == 2) break;
            forn(j,0,ind[i].size())
            {
                if(ind[i][j] == sum)
                {
                    pri++;
                    cout << i+1 << " " << j+1 << endl;
                    break;
                }
            }
        }
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
