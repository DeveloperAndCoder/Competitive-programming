#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

#define N 1000010
#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll ans = 0;

void merge(string A[], int p, int mid, int r)
{
    int n1 = mid+1-p, n2 = r-mid;
    string L[n1], R[n2];
    forn(i,0,n1)
    {
        L[i] = A[p+i];
    }
    forn(i,0,n2)
    {
        R[i] = A[mid+1+i];
    }
    string C[n1+n2];
    int l_i = 0, r_i = 0, i = 0;
    for(i=0;i<n1+n2;i++)
    {
        if(l_i >= n1 || r_i >= n2) break;
        if(L[l_i] <= R[r_i])
        {
            //cout << "in";
            C[i] = L[l_i++];
        }
        else
        {
            //cout << "out";
            ans += ((ll)n1-l_i);
            C[i] = R[r_i++];
        }
    }
    while(l_i < n1)
    {
        C[i] = L[l_i];
        i++;
        l_i++;
    }
    while(r_i < n2)
    {
        C[i] = R[r_i];
        r_i++;
        i++;
    }
    forn(i,0,n1+n2)
    {
        A[i+p] = C[i];
    }
    return;
}

void mergesort(string A[], int p, int r)
{
    if(p >= r) return;
    int mid = p + (r-p)/2;
    mergesort(A, p, mid);
    mergesort(A, mid+1, r);
    merge(A, p, mid, r);
    return;
}

int main()
{
    boost;
    int n;
    cin >> n;
    string A[n];
    forn(i,0,n) cin >> A[i];
    sort(A, A+n);
    //forn(i,0,n) cout << A[i] << " ";
    forn(i,0,n)
    {
        reverse(A[i].begin(), A[i].end());
    }
    /*
    cout << endl;
    forn(i,0,n) cout << A[i] << " ";
    cout << endl;
    */
    mergesort(A,0,n-1);
    /*
    cout << endl;
    forn(i,0,n) cout << A[i] << " ";
    cout << endl;
    */

    cout << ans << endl;
    return 0;
}
