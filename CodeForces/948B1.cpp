#include<bits/stdc++.h>
using namespace std;
int m[1000010];
int main(){
	for(int i=2;i<=1000000;i++)
		if(!m[i])for(int j=i*2;j<=1000000;j+=i)m[j]=i;
	int X,ans;
	cin>>X;
	ans=X;
	for(int i=X-m[X]+1;i<=X;i++)
		ans=min(ans,i-m[i]+1);
	cout<<ans<<endl;
	return 0;
}
