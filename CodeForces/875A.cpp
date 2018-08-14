#include<iostream>
#include<vector>

typedef long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int n;
    cin >> n;
    vector<long long int> v;
    long long int i = max(n-81,0LL);
    long long int c = 0;
    long long int d = 0;
    while(i <= n)
    {
        long long int sum = 0;
        long long int p = i;
        if(p%10==0 || i == n-81 || i == 0)
        {
            while(p)
            {
                sum += p%10;
                p/=10;
            }
            c = sum;
            sum = 0;
        }
        else
            c++;
        sum = i+c;
       // cout << "i = " << i << " sum = " << sum << endl;
        if(sum == n)
            {v.push_back(i);}
        i++;
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
    return 0;
}
