#include<bits/stdc++.h>

#define ll unsigned long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

using namespace std;

pair<int,int> parent[100005];
int rank_[100005];
bool bipartite[100005];

void make_set(int v) {
    parent[v] = make_pair(v, 0);
    rank_[v] = 0;
    bipartite[v] = true;
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        cout << v << "'s parent is " << parent[v].second << " parity = " << parity << endl;
        parent[v].second ^= parity;
        cout << "changed to " << parent[v].second << endl;
    }
    return parent[v];
}

void add_edge(int a, int b) {
    pair<int, int> pa = find_set(a);
    a = pa.first;
    int x = pa.second;

    pair<int, int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;

    if (a == b) {
        if (x == y)
            {
                cout << "marked non bipartite " << a << endl;
                cout << "x = " << x << endl;
                bipartite[a] = false;
            }
    } else {
        if (rank_[a] < rank_[b])
            swap (a, b);
        parent[b] = make_pair(a, x^y^1);
        bipartite[a] &= bipartite[b];
        if (rank_[a] == rank_[b])
            ++rank_[a];
    }
}

bool is_bipartite(int v) {
    return bipartite[find_set(v).first];
}

int gcd(ll a, ll b)
{
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main()
{
    //boost;
    int n, m;
    cin >> n >> m;
    int teeth[n];
    forn(i,0,n) cin >> teeth[i];
    forn(i,0,n) make_set(i);
    while(m--)
    {
        int T;
        cin >> T;
        if(T == 1)
        {
            int X, C;
            cin >> X >> C;
            teeth[X-1] = C;
        }
        else if(T == 2)
        {
            int X, Y;
            cin >> X >> Y;
            X--; Y--;
            add_edge(X,Y);
        }
        else
        {
            int X, Y, V;
            cin >> X >> Y >> V;
            X--; Y--;
            int rootX = find_set(X).first;
            int rootY = find_set(Y).first;
            //cout << rootX << " " << rootY << " " << dxy << endl;
            if(is_bipartite(X) == false || is_bipartite(Y) == false || rootX != rootY)
            {
                cout << 0 << endl;
            }
            else
            {
                bool dxy = parent[X].second ^ parent[Y].second;
                if(dxy&1)
                {
                    cout << "-";
                    ll num = 0LL;
                    ll den = 0LL;
                    num = V*1LL*teeth[X];
                    den = teeth[Y];
                    //cout << X << " " << teeth[X] << " " << Y << " " << teeth[Y] << endl;
                    int g = gcd(num, den);
                    num /= g;
                    den /= g;
                    cout << num << "/" << den << endl;
                }
                else
                {
                    ll num = 0LL;
                    ll den = 0LL;
                    num = V*1LL*teeth[X];
                    den = teeth[Y];
                    //cout << X << " " << teeth[X] << " " << Y << " " << teeth[Y] << " " << num << " " << den << endl;
                    int g = gcd(num, den);
                    num /= g;
                    den /= g;
                    cout << num << "/" << den << endl;
                }
            }
        }
        /*
        cout << "***********************************\n";
        forn(i,0,n) cout << offset[i] << " ";
        cout << "\n*********************************\n";
        cout << endl;
        */

    }
    //forn(i,0,n) cout << i << " " << root(dsu, i) << " " << offset[i] << endl;
}

