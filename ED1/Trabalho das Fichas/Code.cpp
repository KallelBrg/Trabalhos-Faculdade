#include <iostream>
#include "Queue.h"
#include "Ficha.h"

using namespace std;

#define pb push_back

char saveA, saveV, saveR;

void Words(string str, string *V)
{
    stringstream s(str);

    string word;
	
	int position=0;
    while (s >> word)
    {
		if(word[1] == 'A')
		{
			saveA=word[0];
		}
		else if(word[1] == 'V')
		{
			saveV=word[0];
		}
		else if(word[1] == 'R')
		{
			saveR=word[0];
		}
        V[position]=word;
        position++;
	}
}

int main()
{
	Queue<Ficha> A, V, R, B;
	string fichas[52];
	string str;
	getline(cin, str);
	Words(str, fichas);
	for(int i=0; i<52; i++)
	{
		string aux=fichas[i];
		Ficha mov;
		mov.n = aux[0];
		mov.cor = aux[1];
		mov.pos = aux[2];
		if(aux[1] == 'A' || saveA == aux[0])
		{
			A.push(mov);
		}
		else if(aux[1] == 'V' || saveV == aux[0])
		{
			V.push(mov);
		}
		else if(aux[1] == 'R' || saveR == aux[0])
		{
			R.push(mov);
		}
		else
		{
			B.push(mov);
		}
	}
	
	Stack<Ficha> Torres[6];
	bool ok=true;
	int save;
	while((int)Torres[0].size()!=6 || (int)Torres[1].size()!=6 || (int)Torres[2].size()!=6 || (int)Torres[3].size()!=6 || (int)Torres[4].size()!=6 || (int)Torres[5].size()!=6)
	{
		Ficha mov=A.front();
		save=mov.pos-49;
		if(mov.cor != 'P' && ok)
		{
			for(int i=0; i<6; i++)
			{
				if(Torres[(mov.pos-49+i)%6].size()!=6)
				{
					Torres[(mov.pos-49+i)%6].push(A.pop());
					i=6;
				}
			}
		}
		if(mov.cor == 'P' && ok)
		{
			if(Torres[save].size()==0) A.pop();
			else
			{
				Torres[save].pop();
				A.pop();
			}
		}
		if((int)Torres[0].size()==6 && (int)Torres[1].size()==6 && (int)Torres[2].size()==6 && (int)Torres[3].size()==6 && (int)Torres[4].size()==6 && (int)Torres[5].size()==6) ok=false;
		
		
		
		mov=V.front();
		save=mov.pos-49;
		if(mov.cor != 'P' && ok)
		{
			for(int i=0; i<6; i++)
			{
				if(Torres[(mov.pos-49+i)%6].size()!=6)
				{
					Torres[(mov.pos-49+i)%6].push(V.pop());
					i=6;
				}
			}
		}
		if(mov.cor == 'P' && ok)
		{
			if(Torres[save].size()==0) V.pop();
			else
			{
				Torres[save].pop();
				V.pop();
			}
		}
		if((int)Torres[0].size()==6 && (int)Torres[1].size()==6 && (int)Torres[2].size()==6 && (int)Torres[3].size()==6 && (int)Torres[4].size()==6 && (int)Torres[5].size()==6) ok=false;
		
		mov=R.front();
		save=mov.pos-49;
		if(mov.cor != 'P' && ok)
		{
			for(int i=0; i<6; i++)
			{
				if(Torres[(mov.pos-49+i)%6].size()!=6)
				{
					Torres[(mov.pos-49+i)%6].push(R.pop());
					i=6;
				}
			}
		}
		if(mov.cor == 'P' && ok)
		{
			if(Torres[save].size()==0) R.pop();
			else
			{
				Torres[save].pop();
				R.pop();
			}
		}
		if((int)Torres[0].size()==6 && (int)Torres[1].size()==6 && (int)Torres[2].size()==6 && (int)Torres[3].size()==6 && (int)Torres[4].size()==6 && (int)Torres[5].size()==6) ok=false;
		
		mov=B.front();
		save=mov.pos-49;
		if(mov.cor != 'P' && ok)
		{
			for(int i=0; i<6; i++)
			{
				if(Torres[(mov.pos-49+i)%6].size()!=6)
				{
					Torres[(mov.pos-49+i)%6].push(B.pop());
					i=6;
				}
			}
		}
		if(mov.cor == 'P' && ok)
		{
			if(Torres[save].size()==0) B.pop();
			else
			{
				Torres[save].pop();
				B.pop();
			}
		}
		if((int)Torres[0].size()==6 && (int)Torres[1].size()==6 && (int)Torres[2].size()==6 && (int)Torres[3].size()==6 && (int)Torres[4].size()==6 && (int)Torres[5].size()==6) ok=false;

	}
	
	char matriz[6][6];
	
	int andar=0;
	cout << endl <<endl;
	cout << "Table of Game" << endl << endl;
	while(!Torres[0].empty())
	{
		matriz[andar++][0]=Torres[0].pop().cor;
	}
	andar=0;
	while(!Torres[1].empty())
	{
		matriz[andar++][1]=Torres[1].pop().cor;
	}
	andar=0;
	while(!Torres[2].empty())
	{
		matriz[andar++][2]=Torres[2].pop().cor;
	}
	andar=0;
	while(!Torres[3].empty())
	{
		matriz[andar++][3]=Torres[3].pop().cor;
	}
	andar=0;
	while(!Torres[4].empty())
	{
		matriz[andar++][4]=Torres[4].pop().cor;
	}
	andar=0;
	while(!Torres[5].empty())
	{
		matriz[andar++][5]=Torres[5].pop().cor;
	}
	//Imprimir a tabela do jogo
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<6; j++)
		{
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	
	//Mão dos jogadores
	cout << endl << endl;
	cout << "Hand of Players" << endl;
	cout << "Deck color A: ";
	while(!A.empty())
	{
		Ficha mov=A.pop();
		cout << mov.n-48 << mov.cor << mov.pos << " ";
	}
	cout << endl;
	cout << "Deck color V: ";
	while(!V.empty())
	{
		Ficha mov=V.pop();
		cout << mov.n-48 << mov.cor << mov.pos << " ";
	}
	cout << endl;
	cout << "Deck color R: ";
	while(!R.empty())
	{
		Ficha mov=R.pop();
		cout << mov.n-48 << mov.cor << mov.pos << " ";
	}
	cout << endl;
	cout << "Deck color B: ";
	while(!B.empty())
	{
		Ficha mov=B.pop();
		cout << mov.n-48 << mov.cor << mov.pos << " ";
	}
	cout << endl;
	//Quem vai ganhar o jogo
	int win[4]={0,0,0,0};
	for(int i=0; i<6; i++)
	{
		if(matriz[i][i]=='A')win[0]++;
		if(matriz[i][i]=='V')win[1]++;
		if(matriz[i][i]=='R')win[2]++;
		if(matriz[i][i]=='B')win[3]++;
	}
	int m=-1;
	for(int i=0; i<4; i++)
	{
		if(win[i]>m)m=win[i];
	}
	cout << endl << endl;
	cout << "Vencedor(es)" << endl;
	if(m == win[0]) cout << "A ";
	if(m == win[1]) cout << "V ";
	if(m == win[2]) cout << "R ";
	if(m == win[3]) cout << "B ";
	cout << endl;
}
