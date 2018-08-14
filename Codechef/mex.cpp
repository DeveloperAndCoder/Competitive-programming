#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int i=0;
        int d=0;
        int k=0;
        int n;
        cin>>n;
        cin>>k;
        int A[n];
        for(i=0;i<n;i++)
            cin>>A[i];
        sort(A,A+n);
        for(i=0;i<n;i++)
        {
            if(A[i]!=i+d && k!=0)
            {
                d=A[i]-i;
                k--;
            }
            else if(A[i]!=i+d && k==0)
            {
                cout<<i+d << endl;
                break;
            }

        }
        if(i==n)
        {
            cout<<A[n-1]+k+1 << endl;
        }
    }
}
