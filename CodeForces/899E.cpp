#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1)
#define mod 1000000007
#define ll long long
#define nitro std::ios_base::sync_with_stdio (false); cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define vi vector < ll >
#define INV 333333336
#define arr(a,n) for(int i=0;i<n;i++) cin >> a[i];
/*
bool sortbysec(const pair<ll,ll> &a,
              const pair<ll,ll> &b){
    return (a.second < b.second);
}

inline ll mx(ll a,ll b){
	if(a > b) return a;
	else return b;
}

ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}

ll power(ll x,ll y,ll p){
    ll res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;

        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

ll solve(ll x,ll n){
	ll r;
	if(x <= n)
		r = (x-1)/2;
	else
		r = (n-(x-n)+1)/2;
	if(r > 0) return r;
	else return 0;
}
*/
int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif

	int i,n;
	cin >> n;
	ll A[n+1];
	arr(A,n);

	set < pair <int,int> > s1;
	set < pair <int,int> > s2;

	i=0;
	int c = 0;
	while(i < n){
		int j = i;
		c=0;
		while(j < n and A[i] == A[j]){
			j++;
			c++;
		}
		s1.insert(make_pair(-c,i));
		s2.insert(make_pair(i,c));
		i=j;
	}
	/*
    set<pair<int,int>>::iterator it = s1.begin();
    while(it != s1.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    it = s2.begin();
    while(it != s2.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    cout << "---------------------------\n";
    */
	int ans = 0;
	while(!s1.empty()){
		pair <int,int> p;
		p = *(s1.begin());
		set < pair <int,int> >::iterator it;
		pair < int,int> p1;
		p1 = make_pair(p.second,-p.first);
		it = s2.lower_bound(p1);
        //cout << it->first << " " << it->second << endl;
		if(it != s2.begin()){
		    //cout << "in\n";
			it--;
			int l = it->first;
			int val1 = it->second;
			int val2;
			int r;
			it++;
			it++;
			if(it != s2.end())
            {
				r = it->first;
				if(A[l] == A[r])
                {
					int val2 = it->second;
					s2.erase(make_pair(l,val1));
					s2.erase(make_pair(r,val2));

					s2.insert(make_pair(l,val1+val2));

					s1.erase(make_pair(-val1,l));
					s1.erase(make_pair(-val2,r));

					s1.insert(make_pair(-(val1+val2),l));
				}
			}
		}

		s2.erase(p1);
		s1.erase(make_pair(-p1.second,p1.first));
		ans++;
	}
	cout << ans << "\n";

	return 0;
}
