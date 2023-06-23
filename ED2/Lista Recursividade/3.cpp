#include <bits/stdc++.h>

using namespace std;

int dp[100000];

int fat(int x)
{
	if(dp[x] != 0) return dp[x];
	if(x==1 || 0) return dp[x]=1;
	return dp[x]=fat(x-1)*x;
}

int main()
{
	int n; cin >> n;
	cout << fat(n) << endl;
}
