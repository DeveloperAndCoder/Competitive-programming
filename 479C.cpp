#include<iostream>

#define forn(i,a,b) for(int i =a; i < b; i++)

using namespace std;

void merge_(int a[], int b[], int p, int mid, int r);
void print(int a[], int n);
void merge_sort(int a[], int b[], int p, int r)
{
    if(p >= r) return;
    int mid = p + (r-p)/2;
    merge_sort(a, b, p, mid);
    merge_sort(a, b, mid+1, r);
    merge_(a,b,p,mid,r);
    return;
}

void merge_(int a[], int c[], int p, int mid, int r)
{
   // cout << "p = " << p << " mid = " << mid << " r = " << r << endl;
    int i = p;
    int j = mid+1;
    int b[r-p+1];
    int b_[r-p+1];
    int k=0;
    for(k = 0; k < r-p+1; k++)
    {
        if(i > mid || j > r)
            break;
        if(a[i] < a[j] || ((a[i] == a[j]) && (c[i] < c[j])))
        {
            b[k] = a[i];
            b_[k] = c[i++];
        }
        else
        {
            b_[k] = c[j];
            b[k] = a[j++];
        }
    }
    while(i <= mid) {
            b_[k] = c[i];
            b[k++] = a[i++];
    }
    while(j <= r) {
            b_[k] = c[j];
            b[k++] = a[j++];
    }
  //  print(a,2);
    k = 0;
    forn(i,p,r+1) {
        c[i] = b_[k];
        a[i] = b[k++];
    }
   // print(a,2);
    return;
}
void print(int a[], int n)
{
    forn(i,0,n) cout << a[i] << " ";
    cout << '\n';
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int a[n], b[n];
    forn(i,0,n) cin >> a[i] >> b[i];
    merge_sort(a,b,0,n-1);
     // if(a[0] == 332)
    {
    //    print(a,n);
      //  print(b,n);
     //   return 0;
    }
    bool inc = true;
    int day = 0;
    int day2 = b[0];
    forn(i,0,n)
    {
        if(b[i] >= day)
        day = max(day, min(a[i],b[i]));
        else
            day = max(day, a[i]);
    }
    //if(inc) day = min(day, day2);
    cout << day;
    return 0;
}
