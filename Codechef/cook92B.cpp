#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<stack>

#define forn(i,a,n) for(int i = 0; i < n; i++)
#define ll long long
#define eb emplace_back
#define pb push_back
#define mem(array,value) memset(array, value, sizeof(array))
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int M = 1000000001;

using namespace std;

int main()
{
    //boost;
    int t;
    cin >> t;
    vector<int> sub;
    int i = 1;
    int x = 1;
    while(x <= M)
    {
        x = i*(i+1)/2;
        sub.pb(x);
        i++;
        //cout << i << " " << x << endl;
    }
    x = i+1+x;
    sub.pb(x);
    while(t--)
    {
        int x;
        cin >> x;
        //x--;
        int i=0,t=1;
        vector<int>::iterator it = sub.begin();
        it = upper_bound (sub.begin(), sub.end(), x);
        it--;
        //cout << *it << " ";
        t += (it-sub.begin());
        t += min(x-*it, *(it+1)-x+1);
        cout << t << '\n';
    }
    return 0;
}
