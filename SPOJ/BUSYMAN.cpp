#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,int> &p1,const pair<int,int> &p2)
{
    return p1.second < p2.second;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        pair<int, int> time[n];
        for(int i = 0; i < n; i++)
        {
            int s, e;
            cin >> s >> e;
            time[i].first = s;
            time[i].second = e;
        }
        sort(time, time + n, cmp);
        int last_end = 0;
        long ans = 0l;
        for(int i = 0; i < n; i++)
        {
            if(time[i].first >= last_end) {
                ans++;
                last_end = time[i].second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
