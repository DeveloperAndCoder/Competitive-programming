#include<iostream>
#include<queue>
using namespace std;
int main()
{
   int n;
   cin >> n;
   int arr[n],i;
   int count1=0,count2=0,ans=0;
   for(i=0;i<n;i++)
    {
        cin >> arr[i];
        if(arr[i] == 1) count1++;
    }
   for(i = 0;i < n; i++)
   {
       if(arr[i] == 1)
       {
          if(arr[i+1] == 1)
          {
                count2++;
          }
          else
          {
              if(count2 != count1)
                ans = ans + count2 + 2;
              else
                ans = ans + count2 + 1;
              count2 = 0;
          }
       }
   }
   if(count1 > 0)
   ans--;
   cout << ans;
    return 0;
}
