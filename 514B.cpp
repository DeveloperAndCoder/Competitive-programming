#include<iostream>
#include<algorithm>
#define INT_MAX 10000
using namespace std;

 bool func(double i, double j)
 {
     return i<j;
 }
 int main()
 {
     long long int n, x0, y0;
     cin >> n >> x0 >> y0;
     long long ans=0;
     double point[n];
      long long int i,a,b;
     for(i = 0; i < n; i++)
     {
         cin >> a >> b;
         if(a != x0)
         point[i] = (b-y0)/(double)(a-x0);
         else
            point[i] = INT_MAX;
     }
     sort(point,point+n,func);
     for (i = 0; i < n-1; i++)
     {
         if(point[i] == point[i+1])
            continue;
         else
         {
             ans++;
         }
     }
     ans++;
     cout << ans;
 }
