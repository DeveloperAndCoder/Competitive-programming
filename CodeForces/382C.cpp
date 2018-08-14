#include<iostream>
#include<algorithm>
#include<vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    forn(i,0,n) cin >> a[i];
    sort(a,a+n);
    if(n == 1)
    {
        cout << -1;
        return 0;
    }
    if(n == 2)
    {
        int diff = a[1]-a[0];
        if(diff == 0)
        {
            cout << 1;
            cout << endl << a[0];
            return 0;
        }
        if(diff%2 == 1)
        {
            cout << 2 << endl;
            cout << a[0]-diff << " " << a[1]+diff;
        }
        else
        {
            diff /= 2;
            cout << 3 << endl;
            cout << a[0]-2*diff << " " << a[0]+diff << " " << a[1] + 2*diff;
        }
        return 0;
    }
    vector<int> ans;
    int diff = a[1]-a[0];
    forn(i,0,n-1)
    {
        int curr = a[i+1]-a[i];
        if(curr < diff) diff = curr;
    }
    bool check = true;
    //cout << diff << endl;
    forn(i,1,n)
    {
        if(a[i] == a[i-1]+diff)
        {
            continue;
        }
        else
        {
            if(check == false)
            {
                cout << 0;
                return 0;
            }
            if(a[i] == a[i-1]+2*diff && check)
            {
                ans.emplace_back(a[i-1]+diff);
                check = false;
            }
            else
            {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if(check)
    {
        if(diff == 0)
        {
            cout << 1 << endl;
            cout << a[0];
        }
        else
        {
            cout << 2 << endl;
            cout << a[0]-diff << " " << a[n-1]+diff;
        }
    }
    else
    {
        cout << ans.size() << endl;
        cout << ans[0];
    }
    return 0;
}
