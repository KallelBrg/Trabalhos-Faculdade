#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector<int>vet;


void Together(vector<int>&vet, int m, int Pi, int Pf)
{
	int i=Pi;
	int j=m+1;
	vector<int>ans;
	while(i<=m && j<=Pf)
	{
		if(vet[i]<vet[j])
		{
			ans.pb(vet[i]);
			i++;
		}
		else
		{
			ans.pb(vet[j]);
			j++;
		}
	}
	
	while(i<=m)
	{
		ans.pb(vet[i]);
		i++;
	}
	while(j<=Pf)
	{
		ans.pb(vet[j]);
		j++;
	}
	
	for(int i=Pi; i<=Pf; i++)
	{
		vet[i]=ans[i-Pi];
	}	
}



void MergeSort(vector<int>&vet, int Pi, int Pf)
{
	if(Pf > Pi)
	{
		int m = (Pi+Pf)/2;
		MergeSort(vet, Pi, m);
		MergeSort(vet, m+1, Pf);
		Together(vet, m, Pi, Pf);
	}
}

int main()
{
	int N;
	cout << "Insira a quantidade de elementos: ";
	cin >> N;
	cout << endl;
	cout << "Insira os elementos: ";
	for(int i=0 ;i<N; i++)
	{
		int x; cin >> x;
		vet.pb(x);
	}
	int Pi=0;
	int Pf=vet.size()-1;
	MergeSort(vet, Pi, Pf);
	cout << endl;
	cout << "Vetor Ordenado = ";
	for(int i=0; i<N; i++)
	{
		cout << vet[i] << " ";
	}
	cout << endl;
}
