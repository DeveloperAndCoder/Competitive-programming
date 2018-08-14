#include<iostream>
#include<vector>
#include<algorithm>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v[n];
        forn(i,0,n)
        {
            forn(j,0,n)
            {
                int k;
                cin >> k;
                v[i].push_back(k);
            }
            sort(v[i].begin(), v[i].end());
        }
        /*
        forn(i,0,n)
        {
            forn(j,0,n)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        */
        ll sum = v[n-1][n-1];
        int prev = sum;
        for(int i = n-2; i >= 0; i--)
        {
            int j = n-1;
            while(j >= 0 && v[i][j] >= prev)
                j--;
            if(j < 0)
            {
                cout << -1 << '\n';
                goto e;
            }
            prev = v[i][j];
            sum += prev;
        }
        cout << sum << '\n';
        e:;
    }
    return 0;
}
