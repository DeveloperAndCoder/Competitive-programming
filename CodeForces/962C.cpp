// Author : Anurag Shah
// @Copyright : 2018
// IIT Jodhpur

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define eb emplace_back
#define pb push_back
#define fr first
#define sc second
#define sins insert

typedef long long ll;

#define M 2000000000
const int mod = 1000000007;

using namespace std;

bool check(string str1, string str2, int m, int n)
{
   int j = 0; // For index of str1 (or subsequence

   // Traverse str2 and str1, and compare current character
   // of str2 with first unmatched char of str1, if matched
   // then move ahead in str1
   for (int i=0; i<n&&j<m; i++)
       if (str1[j] == str2[i])
         j++;

   // If all characters of str1 were found in str2
   return (j==m);
}

int main()
{
    vector<string> sq;
    ll i = 1;
    while(i*i <= M)
    {
        sq.eb(to_string(i*i));
        i++;
    }
    string num;
    cin >> num;
    ll ans = num.size()+1;
    forn(i,0,sq.size())
    {
        //int n = check(sq[i], num);
        if(check(sq[i], num, sq[i].size(), num.size()))
        {
            ans = min(ans, (ll)num.size()-(ll)sq[i].size());
           // cout << sq[i] <<  " " << num.size() - sq[i].size() << endl;
        }
    }
    if(ans == num.size()+1)
    ans = -1;
    cout << ans;
    return 0;
}
