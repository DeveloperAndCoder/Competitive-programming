#include<iostream>
#include<queue>

using namespace std;

int main()
{
    long long int n,t,c,i,count=0,ans=0;
    cin >> n >> t >> c;
    queue<long long int> q;
    for(i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        q.push(a);
    }
    for(i = 0; i <n; i++)
    {
        if(q.front() > t)
        {
            q.pop();
            if(count >= c)
            ans+=(count-c+1);
            count = 0;
        }
        else
        {
            count++;
            q.pop();
        }
    }
    if(count >= c)
    ans+=(count-c+1);
    cout << ans;
}
