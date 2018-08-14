#include <iostream>
#include<stdio.h>
using namespace std;
int c;
inline int foo(bool A[], int counti, int n)
{
    int j = c-1;
    //cout << "c = " << c << endl;
    counti = counti - (n-c);
    while(!A[j] && j >= 0)
    {
        counti--;
        j--;
        c = j+1;
    }
    return counti+1;
}

int main()
{
    int n,curr,i = 0,x;
    scanf("%d",&n);
    bool A[n];
    c = n;
    for(int i = 0; i < n; i++)
    {
        A[i] = true;
    }
    cout << "1" << " ";
    for(i = 1; i <= n; i++)
    {
        scanf("%d",&x);
        A[x-1] = false;
        printf("%d ",foo(A, i, n));
    }
    return 0;
}
