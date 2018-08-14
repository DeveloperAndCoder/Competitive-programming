#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<stack>
#include<climits>
#include<map>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define MAX 100001
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int ans = 0;

void merge(int arr[], int p, int mid, int r)
{
    int n1 = mid-p+1, n2 = r-mid;
    int L[n1], R[n2];
    forn(i,0,n1)
    {
        L[i] = arr[p+i];
    }
    forn(j,0,n2)
    {
        R[j] = arr[mid+1+j];
    }
    int C[n1+n2];
    int p1 = 0, p2 = 0, i = 0;
    for(i = 0; i < n1+n2; i++)
    {
        if(p1 >= n1 || p2 >= n2) break;
        if(L[p1] <= R[p2])
        {
            C[i] = L[p1++];
        }
        else
        {
            ans += (n1-p1);
            C[i] = R[p2++];
        }
    }
    while(p1 < n1)
    {
        C[i] = L[p1];
        i++;p1++;
    }
    while(p2 < n2)
    {
        C[i] = R[p2];
        i++;p2++;
    }
    forn(i,0,n1+n2)
    {
        arr[p+i] = C[i];
    }
    return;
}

void mergesort(int arr[], int p, int r)
{
    if(p >= r) return;
    int mid = p + (r-p)/2;      // Prevents overflow
    mergesort(arr,p,mid);
    mergesort(arr,mid+1,r);
    merge(arr,p,mid,r);
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        ans = 0;
        int n;
        cin >> n;
        if(n == 0) break;
        string yoda[n], normal[n];
        forn(i,0,n) cin >> yoda[i];
        forn(j,0,n) cin >> normal[j];
        map<string, int> mp;
        forn(i,0,n)
        {
            mp[normal[i]] = i+1;
        }
        int arr[n];
        forn(i,0,n)
        {
            arr[i] = mp[yoda[i]];
        }
        mergesort(arr, 0, n-1);
        cout << ans << endl;
    }
    return 0;
}
