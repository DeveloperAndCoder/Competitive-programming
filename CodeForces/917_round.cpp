#include<bits/stdc++.h>

using namespace std;

int dn[5005][5005];
int N;
string S;

int main() {

	cin >> S;
	N = S.size();

	int res = 0;
	int x;
	int bonus;

	for(int i=0; i<N; i++) {
		x = 0;
		bonus = 0;
		for(int j=i; j<N; j++) {
			if(S[j] == '(')
				x++;
			else if(S[j] == ')')
				x--;

			else
				bonus++;


			if(x+bonus < 0)
				break;

			if(bonus > x)
				swap(x,bonus);

			if(bonus == x)
				res++;
		}


	}

	cout << res << endl;
}
