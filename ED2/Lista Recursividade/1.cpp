#include <bits/stdc++.h>

using namespace std;

void b(int n,int x){
	if(n>=x){
		cout<<x<<endl;
		b(n,x+1);
	}
}

int main()
{
	int a; cin >> a;
	b(a, 0);
}
