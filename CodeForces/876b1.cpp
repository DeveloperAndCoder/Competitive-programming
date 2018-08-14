#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> v[m];
    int x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        v[x%m].push_back(x);
    }
    int i = 0;
    for(i = 0; i < m; i++)
    {
        if(v[i].size() >= k)
            break;
    }

    if(i == m)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes\n";
        for(int j = 0; j < k; j++)
        {
            cout << v[i][j] << " ";
        }
    }
}
