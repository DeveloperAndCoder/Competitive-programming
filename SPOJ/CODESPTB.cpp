#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <tuple>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAX 1000001

using namespace std;

ll ans = 0;

void merge(int arr[], int p, int mid, int r)
{
    //cout << p << " " << mid << " " << r << endl;
    int L[mid-p+1], R[r-mid];
    int n1 = mid-p+1, n2 = r-mid;
    forn(i,p,mid+1) L[i-p] = arr[i];
    forn(i,mid+1,r+1){
        R[i-mid-1] = arr[i];
    }
    //cout << L[0] << "\t" << R[0] << endl;
    int C[r-p+1];
    int i1 = 0,i2 = 0, i=0;
    for(i = 0; i < r-p+1; i++)
    {
        if(i1 >= mid-p+1 || i2 >= r-mid) break;
        if(L[i1] <= R[i2])
            {
                C[i] = L[i1++];
            }
        else
            {
                ans+=n1-i1;
               // cout << "L[" << i1<< "] = " << L[i1] << " R[" << i2 << "] = " << R[i2] << endl;
                C[i] = R[i2++];
            }
    }
    while(i1 < mid-p+1)
    {
        //ans+=(i2+1);
        //cout << "L[" << i1<< "] = " << L[i1] << endl;
       // cout << "i1 = " << i1 << endl;
        C[i] = L[i1];
        i++;i1++;
    }
    while(i2 < r-mid)
    {
     //   cout << "i2 = " << i2 << endl;
        C[i] = R[i2];
        i++,i2++;
    }
    forn(i,p,r+1) arr[i] = C[i-p];
   // forn(i,0,4) cout << arr[i] <<" ";
   // cout << endl;
    return;
}

void mergesort(int arr[], int p, int r)
{
    if(p >= r) return;
    int mid = (p+r)/2;
    //cout << p << " "<< r << " " << mid << endl;
    mergesort(arr, p, mid);
    mergesort(arr, mid+1, r);
    merge(arr,p,mid,r);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        forn(i,0,n)
        {
            cin >> arr[i];
        }
        mergesort(arr,0,n-1);
        cout<<ans<<endl;
        ans=0;
    }
}
