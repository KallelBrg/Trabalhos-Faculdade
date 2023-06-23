#include <bits/stdc++.h>

using namespace std;

void b(int n){
	if(n>=0){
		cout<<n<<endl;
		b(n-1);
	}
}

int main()
{
	int a; cin >> a;
	b(a);
}
