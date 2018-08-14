#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>

#define forn(i,a,b) for(int i = a; i < b; i++)
typedef long long ll;

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    set<char> s;
    forn(i,0,n) s.insert(a[i]);
    set<char>::iterator it = s.begin();
    if(k > n)
    {
        cout << a;
        k -= n;
        while(k--) cout << *it;
    }
    else
    {
        int pos = k-1;
        it = s.end();
        it--;
        //cout << *it << endl;
        while(a[pos] == *it)
            pos--;
        it = s.find(a[pos]);
        it++;
        a[pos] = *it;
        it = s.begin();
        forn(i,0,pos+1) cout << a[i];
        forn(i,pos+1,k) cout << *it;
    }
    return 0;
}
