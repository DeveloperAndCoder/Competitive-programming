#include <bits/stdc++.h>

using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define N (int)2e5+1

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n], b[n];
    forn(i,0,n)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+ n);
    vector<int> mx(k);
    int k1 = k;
    int sum = 0;
    int j = 0;
    for(int i = n-1; i >= 0 && k1; i--, k1--)
    {
        sum += b[i];
        mx[j++] = b[i];
    }
    sort(mx.begin(), mx.end());
    int cnt = 0;
    vector<int> part;
    forn(i,0,n)
    {
        auto it = lower_bound(mx.begin(), mx.end(), a[i]);
        if(it != mx.end() && *it == a[i])
        {
            mx.erase(it);
            part.push_back(cnt+1);
            cnt = 0;
        }
        else cnt++;
    }
    part[k-1] += cnt;
    cout << sum << endl;
    forn(i,0,part.size())
    cout << part[i] << " "[i == k-1];
}

