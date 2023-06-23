#include <bits/stdc++.h>
#include "stack.h"

using namespace std;

StackVet::StackVet(int n)
{
	vet = new int[n];
	N=n;
	Top=-1;
}

StackVet::~StackVet()
{
	delete[] vet;
}

bool StackVet::push(int x)
{
	if(Top<N-1)
	{
		vet[++Top]=x;
		return true;
	}
	return false;
}

int StackVet::top()
{
	return vet[Top];
}

void StackVet::pop()
{
	if(Top>=0)
	{
		Top--;
	}
}

int StackVet::size()
{
	return Top+1;
}

bool StackVet::empty()
{
	return !(Top+1);
}

bool StackVet::full()
{
	return !(Top+1-N);
}

QueueOfStack::QueueOfStack(int n)
{
	stk1 = new StackVet(n);
	stk2 = new StackVet(n);
}

QueueOfStack::~QueueOfStack()
{
	delete[] stk1;
	delete[] stk2;
}

bool QueueOfStack::push(int x)
{
	return stk1->push(x);
}

int QueueOfStack::size()
{
	return stk1->size();
}

bool QueueOfStack::empty()
{
	return stk1->empty();
}

int QueueOfStack::front()
{
	while(!stk1->empty())
	{
		stk2->push(stk1->top());
		stk1->pop();
	};
	int save=stk2->top();
	while(!stk2->empty())
	{
		stk1->push(stk2->top());
		stk2->pop();
	}
	return save;
}

void QueueOfStack::pop()
{
	while(!stk1->empty())
	{
		stk2->push(stk1->top());
		stk1->pop();
	}
	
	stk2->pop();
	while(!stk2->empty())
	{
		stk1->push(stk2->top());
		stk2->pop();
	}
}

int main()
{
	int n;
	cin >> n;
	QueueOfStack a(n);
	for(int i=0; i<n; i++)
	{
		int x; cin >> x;
		a.push(x);
	}
	a.pop();
	cout << "Tam = " << a.size() << endl;
	
}
