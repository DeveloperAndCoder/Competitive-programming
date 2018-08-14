#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    long long sum = n*(n+1);
    sum/=2;
    if(sum % 2 == 1) cout << 1;
    else cout << 0;
    cout << '\n';
    sum/=2;
    vector<int> ans;
    //cout << "sum = " << sum << '\n';
    while(sum > n)
    {
        ans.push_back(n);
        sum-=n;
        --n;
    //cout << "sum = " << sum << "n = " << n << '\n';
    }
    if(sum > 0)
    {
        ans.push_back(sum);
        sum = 0;
    }
    cout << ans.size() << " ";
    for(int i = 0;i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
