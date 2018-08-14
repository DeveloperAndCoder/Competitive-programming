#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long solve(int n, unordered_map<int, long long> &ans)
{
    if(n == 0 || n == 1) return n;
    if(ans.find(n) != ans.end()) return ans[n];
    ans[n] = max((long long)n, solve(n/2, ans) + solve(n/3, ans) + solve(n/4, ans));
    return ans[n];
}

int main()
{
    unordered_map<int, long long> ans;
    int n;
    while(cin >> n)
    {
        cout << solve(n, ans) << endl;
    }
    return 0;
}
