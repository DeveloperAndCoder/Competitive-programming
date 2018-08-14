#include<iostream>

using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int app[n],i,p=0,ne=0,pos[n];
    for(i=0;i<n;i++)
    {
        cin >> pos[i] >> app[i];
        if(pos[i] > 0)
            p++;
        else if(pos[i] < 0)
            ne++;
    }
    long long int count = 0,sum=0;
    if (p > ne)
    {
        for(i = 0; i < n; i++)
        {
            if (pos[i] > 0)
            {
                sum+=app[i];
                count++;
                if(count == ne+1)
                    break;
            }
            else
                sum+=app[i];
        }
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            if (pos[i] < 0)
            {
                sum+=app[i];
                count++;
                if(count == p+1)
                    break;
            }
            else
                sum+=app[i];
        }
    }
    cout << sum;
}
