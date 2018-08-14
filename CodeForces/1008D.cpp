#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

const int N = 1e5+1;
vector<int> div1[N];
bool vis[N];

void init()
{
    for(int i = 2; i < N; i++)
    {
        //cout << i << "\n";
        for(int j = i*i; j < N; j+=i)
        {
            div1[j].push_back(i);
            if(i != j/i)
            div1[j].push_back(j/i);
        }
    }
}

void divide(int n)
{
    if(vis[n]) return;
    vis[n] = true;
    for(int i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            div1[n].push_back(i);
            if(i != n/i)
            div1[n].push_back(n/i);
        }
    }
    sort(div1[n].begin(), div1[n].end());
    return;
}

long long nCr(int n)
{
    return n*1LL*(n-1)/2;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int A, B, C;
        cin >> A >> B >> C;

        divide(A);
        divide(B);
        divide(C);
        for(auto i : div1[A])
            cout << i << " ";
        cout << endl;
        unordered_set<int> visi;

        ll ans = 0;

        for(auto it : div1[A])
        {
            if(visi.find(it) == visi.end())
            {
                visi.insert(it);
                int n1 = upper_bound(div1[B].begin(), div1[B].end(), it)-1;
                int n2 = div1[C].end() - lower_bound(div1[C].begin(), div1[C].end(), it);
                ans += n1*n2;
                cout << it << " " << n1 << " " << n2 << endl;
            }
        }
        for(auto it : div1[B])
        {
            if(visi.find(it) == visi.end())
            {
                cout << "in?";
                visi.insert(it);
                int n1 = upper_bound(div1[A].begin(), div1[A].end(), it);
                int n2 = div1[C].end() - lower_bound(div1[C].begin(), div1[C].end(), it);
                ans += n1*n2;
            }
        }
        for(auto it : div1[C])
        {
            if(visi.find(it) == visi.end())
            {
                cout << "INNN!";
                visi.insert(it);
                int n1 = upper_bound(div1[B].begin(), div1[B].end(), it);
                int n2 = div1[A].end() - lower_bound(div1[A].begin(), div1[A].end(), it);
                ans += n1*n2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
