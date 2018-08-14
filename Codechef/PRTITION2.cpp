#include<iostream>
#include<vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    int t;
     cin >> t;
     while(t--)
     {
         int n, x;
         cin >> x >> n;
         int i = n;
         vector<int> v(n, -1);
         ll sum = n*(n-1)/2;
         v[x-1] = 2;
         int k = 4;
         if(sum&1 || n == 2 || n == 3)
         {
             cout << "impossible\n";
         }
         else
        {
             while(i > 0)
             {
                 int j = i;
                 k = 1;
                 while(j && k<=5)
                 {
                     if(j == x)
                     {
                        j--;
                        continue;
                     }
                     if(j < 0) break;
                     if(k == 4 || k == 1) v[j] = 1;
                     else v[j] = 0;
                     k++;
                     j--;
                 }
                 i = j;
                 i--;
             }
             if(k == 2)
             {

             }
             forn(i,0,n) cout << v[i];
         }
         cout << endl;
     }
     return 0;
}
