#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define eb emplace_back
#define pb push_back
#define fr first
#define sc second
#define sins insert

typedef long long ll;

#define M 1000000
const int mod = 1000001;

using namespace std;

int ff(ll f_sum[], int s[], int n, ll target, int i)
{
    ll xc = f_sum[n-1]-f_sum[i];
    if(xc <= s[i]) return -1LL;
    ll low = i+1, high = n-1; // numElems is the size of the tay i.e t.size()
    while (low != high && low <= high)
    {
        int mid = (low + high) / 2; // Or a fancy way to avoid int overflow
        ll midv = f_sum[mid]-f_sum[i];
        if (midv <= target) {
            /* This index, and everything below it, must not be the first element
             * greater than what we're looking for because this element is no greater
             * than the element.
             */
            low = mid + 1;
        }
        else {
            /* This element is at least as large as the element, so anything after it can't
             * be the first element that's at least as large.
             */
            high = mid;
        }
}
    return high;
}
int ff1(ll b_sum[], int s[], int n, ll target, int i)
{
    ll xc = b_sum[0]-b_sum[i];
    if(xc <= s[i]) return -1;
    ll high = 0, low = i-1; // numElems is the size of the tay i.e t.size()
    while (low != high && low > high)
    {
        int mid = (low + high) / 2; // Or a fancy way to avoid int overflow
        ll midv = b_sum[mid]-b_sum[i];
        if (midv <= target) {
            /* This index, and everything below it, must not be the first element
             * greater than what we're looking for because this element is no greater
             * than the element.
             */
            low = mid - 1;
        }
        else {
            /* This element is at least as large as the element, so anything after it can't
             * be the first element that's at least as large.
             */
             if(high == mid)
             {
                 if(b_sum[high+1]-b_sum[i] > target) high++;
                 else return high;
             }
             else high = mid;
        }
}
    return high;
}
template<class T>
void print(T a[], int n)
{
    forn(i,0,n) cout << a[i] << " ";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int s[n];
        forn(i,0,n) cin >> s[i];
        ll f_sum[n];
        ll b_sum[n];
        f_sum[0] = s[0];
        b_sum[n-1] = s[n-1];
        forn(i,1,n) f_sum[i] = f_sum[i-1]+s[i];
        forn(i,1,n) b_sum[n-i-1] = b_sum[n-i]+s[n-i-1];
        //print(f_sum,n);
        //print(b_sum,n);
        int p1[n],p2[n];
        int ans[n];
        memset(ans, 0, sizeof(ans));
        memset(p1, 0, sizeof(p1));
        memset(p2, 0 ,sizeof(p2));
        forn(i,0,n)
        {
            int index1 = ff(f_sum, s, n, s[i], i);
            int index2 = ff1(b_sum, s, n, s[i], i);
            if(i < n-1) p1[i+1]++;
            if(i > 0) p2[i-1]++;
            if(index1 != -1 && index1 < n-1) p1[index1+1]--;
            if(index2 != -1 && index2 > 0) p2[index2-1]--;
          //  cout << i << " " << index2 << " " << s[index2] << endl;// << " " << index2 << endl;
        }
        //cout << "\n-------------------\n";
        forn(i,1,n) p1[i] += p1[i-1];
        for(int i = n-2; i >= 0; i--) p2[i] += p2[i+1];
        forn(i,0,n) ans[i] = p1[i]+p2[i];
        //forn(i,0,n) cout << p1[i] << " ";
        //cout << '\n';
        //forn(i,0,n) cout << p2[i] << " ";
        //cout << '\n';
        forn(i,0,n) cout << ans[i] << " ";
        cout << '\n';
    }
}
