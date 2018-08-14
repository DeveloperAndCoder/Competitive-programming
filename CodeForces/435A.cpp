#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int i=0;
    queue<int> q;
    int a;
    for(i;i<n;i++)
    {
        cin >> a;
        q.push(a);
    }
    if(n==1)
    cout << "1";
    else if(m==1)
    cout << n;
    else
    {
    int ans=0,sum=0;
    for(;!q.empty();)
    {
    //     sum = arr[i];
    //     while(sum < m)
    //     {
        //     if(i < n-1 && arr[i+1]+sum <= m)
        //     {
        //         i++;
        //         sum+=arr[i];
        //     }
        //     else if(i == n-1)
        //     {
        //         sum+=arr[n-1];
        //     }
         //}
         while(sum < m)
         {
             if(q.empty())
                break;
           //cout << sum<<" "<<q.front()<<endl;
             if (sum + q.front() <= m)
             {
             sum += q.front();
             q.pop();
             }
             else
             {
             break;
             }
         }
         sum = 0;
        ans++;
    }
    cout << ans;
    }
    return 0;
}
