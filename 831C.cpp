#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    int a[n];
    int b[k];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < k; i++)
        cin >> b[i];
        vector<int> c;
        int ans = 0;
        for(int i = 0; i < k; i++)
            for(int j = 0; j < n; j++)
        {
            int x = b[i] - a[j];
            bool v =false;
            for(int l = 0; l < c.size(); l++)
            {
                if(c[l] == x)
                {
                    v = 1;
                    break;
                }
            }

                if(!v)
                    ans++;
                    else
                        c.push_back(x);
                v = 0;
        }
        cout << ans;
    return 0;
}
