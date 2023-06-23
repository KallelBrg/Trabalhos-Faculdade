#include <bits/stdc++.h>

using namespace std;

int fib(int x)
{
	int v[x];
	if(x == 0) return v[x]=0;
	if(x == 1) return v[x]=1;
	return v[x]=fib(x-1)+fib(x-2);
	
}

int main()
{
	int a; cin >> a;
	cout << fib(a) << endl;
}
