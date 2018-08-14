    #include <iostream>
    #include <vector>
    #include <utility>
    #include <set>
    #include <algorithm>

    using namespace std;
    #define ll long long
#define ul unsigned long long
#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001
#define D 400001
#define mod 1000000007
    typedef vector<int> vi;
    typedef vector<bool> vb;
    typedef pair<int, int> pii;
    typedef vector<pii> vii;
    typedef long long int lli;
    typedef multiset<int> msi;

    #define PRIME 1000000007
    #define MAX_N 4000010

    int product_upto[MAX_N];
    int inverse_upto[MAX_N];

    ul fac[D+2];

void calc()
{
    fac[0] = 1;
    forn(i,1,D+1)
    {
        fac[i] = fac[i-1]*i%mod;
        //cout << i << " "  << fac[i] << endl;
        fac[i]%=mod;
    }
}

ul power(ul x, ul y, ul p)
{
    ul res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
    // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

ul modInverse(ul n, ul p)
{
    return power(n, p-2, p);
}

ul nCr(int n, int r, int p)
{
    if(n < 0) return 1;
    if(r < 0) return 1;
    if(n < r) return 0;
    if (r==0)
        return 1;
    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}

bool cmp(ul x, const pair<ul,ul> &p2)
{
    return x<p2.fr;
}

bool cmp1(const pair<ul,ul> &p1, const pair<ul,ul> &p2)
{
    if(p1.fr == p2.fr)
        return p1.sc<p2.sc;
    return p1.fr<p2.fr;
}

    void init() {
    	product_upto[0] = 1;
    	product_upto[1] = 1;
    	inverse_upto[0] = 1;
    	inverse_upto[1] = 1;

    	long long int temp;

    	for(int i = 2; i < MAX_N; i++) {
    		temp = inverse_upto[PRIME % i];
    		inverse_upto[i] = (temp * (PRIME - PRIME / i)) % PRIME;
    	}

    	for(int i = 2; i < MAX_N; i++) {
    		temp = product_upto[i - 1];
    		product_upto[i] = (temp * i) % PRIME;
    		temp = inverse_upto[i - 1];
    		inverse_upto[i] = (temp * inverse_upto[i]) % PRIME;
    	}
    }

    int combination(int n, int r) {
    	long long int numer = 1, denom = 1;
    	if(n < 0 || r < 0) return 1;
    	if(n < r) return 0;
    	if(n == r) return 1;
    	if(r == 0) return 1;

    	numer = product_upto[n];
    	denom = inverse_upto[r];
    	denom = (denom * inverse_upto[n-r]) % PRIME;
    	long long int ans = 1;
    	ans = (numer * denom) % PRIME;
    	return ans;
    }

    bool compare1(pii& a, pii& b) {
    	if(a.first != b.first) {
    		return a.first < b.first;
    	}
    	return a.second > b.second;
    }

    bool compare2(pii& a, pii& b) {
    	if(a.first != b.first) {
    		return a.first < b.first;
    	}
    	return a.second < b.second;
    }

    int greedy1(vii& points, int N, int K, bool error) {
    	sort(points.begin(), points.end(), compare1);

    	// for(int i = 0; i < N; i++) {
    	// 	cout<<points[i].first<<" "<<points[i].second<<endl;
    	// }

    	msi p;
        //cout << "ABC\n";
    	lli ans = combination(N, K);
        //cout << "A";
    	for(int i = 0; i < N; i++) {
    		while(!p.empty() && *(p.begin()) < points[i].first) {
    			p.erase(p.begin());
    		}
    		ans = (ans + PRIME - combination(p.size(), K - 1))%PRIME;
    		p.insert(points[i].second);
    		//cout << "B " << i << endl;
    	}
    	//cout << " " << ans << " " ;
    	return ans;
    }

    int greedy2(vii& points, int N, int K, bool error) {
    	if(error) cout << "\n----------------\n";
    	int n, k;
        n = N; k = K;
        vector<pair<ul,ul> > seg(n);
        forn(i,0,n)
        {
        	seg[i].fr = points[i].fr;
        	seg[i].sc = points[i].sc;
        }
        if(k == 1)
        {
            return n;
        }
        sort(seg.begin(), seg.end(), cmp1);
        int ans = 0;
        forn(i,0,n)
        {
            int x = upper_bound(seg.begin()+i+1, seg.end(), seg[i].sc, cmp) - seg.begin() - i - 1;
            if(error)
            cout << "\n" << i << " " << x << " ";
            ans += nCr(n-i-1,k-1,mod) - nCr(x,k-1,mod);
            if(error)
            cout << ans << endl;
            ans %= mod;
        }
        if(error)
        {
            cout << ans%mod << endl;
            cout << "---------------\n";
        }
    	return ans;
    }

    void function_check(){

    	int N_MAX = 3;
    	int V_MAX = 4;
    	int c = 1;

    	while(1) {
    		cout<<'\r'<<c++<<flush;

    		int N = 1 + rand()%N_MAX;
    		int K = 2 + rand()%N;
    		vii points(N, pii(0, 0));
    		for(int n = 0; n < N; n++) {
    			int a = 1 + rand()%V_MAX;
    			int b = 1 + rand()%V_MAX;
    			points[n].first = a < b ? a:b;
    			points[n].second = a < b ? b:a;
    		}
    		sort(points.begin(), points.end());
    		//cout << "out" << endl;
    		if(greedy1(points, N, K, false) != greedy2(points, N, K, false)) {
    			cout<<endl<<"Error"<<endl;
    			cout<<greedy1(points, N, K,0)<<" "<<greedy2(points, N, K,1)<<" "<<N<<" "<<K<<endl;
    			cout << endl << "Points : \n";
    			for(int n = 0; n < N; n++) {
    				cout<<"(" << points[n].first<<","<<points[n].second << ")"<<endl;
    			}
    			return;
    		}
    	}
    }

    int main() {
        boost;
    	init();
    	calc();
    	//function_check();
    	//return 0;

        int T;
    	cin>>T;
    	for(int t = 0; t < T; t++) {
    		int N, K;
    		cin>>N>>K;
    		vii points(N, pii(0, 0));
    		for(int n = 0; n < N; n++) {
    			cin>>points[n].first>>points[n].second;
    		}
    		cout<<greedy1(points, N, K,0)<<endl;
    	}
    	return 0;
    }
